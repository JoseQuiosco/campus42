/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:41:35 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/01 17:27:49 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

long	ft_atoi(const char *str)
{
	int	    sign;
	long	result;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (*str - 48) + (result * 10);
		str++;
	}
	return (result * (long)sign);
}

void    init_values(char **argv, int i, t_gdata *g_data)
{
    if (i == 1)
        g_data->total_philos = ft_atoi(argv[i]);
    if (i == 2)
        g_data->ttdie = ft_atoi(argv[i]);
    if (i == 3)
        g_data->tteat = ft_atoi(argv[i]);
    if (i == 4)
        g_data->ttsleep = ft_atoi(argv[i]);
    if (i == 5)
        g_data->total_must_eat = ft_atoi(argv[i]);
    g_data->condition = 0;
}  

int are_right_values(char **argv, t_gdata *g_data)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (0);
            j++;
        }
        init_values(argv, i, g_data);
        i++;
    }
    if (i == 5)
        g_data->total_must_eat = -1;
    return (1);
}

int init_philos(t_philo **philos, t_gdata *g_data, pthread_mutex_t  *forks)
{
    int i;

    *philos = (t_philo *)malloc(g_data->total_philos * sizeof(t_philo));
    if (!(*philos))
        return (0);
    i = 0;
    while (i < g_data->total_philos)
    {
        (*philos + i * sizeof(t_philo))->num = i + 1;
        (*philos + i * sizeof(t_philo))->time_last_meal = 0;
        (*philos + i * sizeof(t_philo))->n_meals = 0;
        (*philos + i * sizeof(t_philo))->g_data = g_data;
        (*philos + i * sizeof(t_philo))->L_fork = &forks[i];
		(*philos + i * sizeof(t_philo))->alive = 1;
        if (i == g_data->total_philos - 1)
            (*philos + i * sizeof(t_philo))->R_fork = &forks[0];
        else
            (*philos + i * sizeof(t_philo))->R_fork = &forks[i + 1];
        printf("Existo! Soy nº %i\n", (*philos + i * sizeof(t_philo))->num);
        i++;
    }    
    return (1);
}

int		print_locked(t_philo *philo)
{
    usleep(1000);
	pthread_mutex_lock(&philo->g_data->write_message);
	printf("Filo %d presente!\n", philo->num);
    printf("Hola muyayo! Soy el filósofo número %d y han pasado %ld ms desde que nací! \n", philo->num, time_of_day() - philo->g_data->time_begin);
	pthread_mutex_unlock(&philo->g_data->write_message);
	philo->alive = 0;
	return (0);
}

void	*is_my_life(void *philo)
{
	t_philo * filo;

	filo = (t_philo *)philo;
    print_locked(filo);
	return (NULL);
}

time_t	time_of_day(void)
{
	struct timeval timer;

    if (!gettimeofday(&timer, NULL))
        return (0);
   return (timer.tv_sec * 1000 + timer.tv_usec / 1000);
}

int		join_the_party(t_philo	*philos)
{
	int	i;
    int total_philos;

	i = 0;
    printf("JOIN\n");
    total_philos = philos[0].g_data->total_philos;
	while (i < total_philos)
	{
		pthread_join(philos[i].philo_thread, NULL);
		i++;
	}
    printf("JOIN2\n");
	i = 0;
	while (i < total_philos)
	{
		pthread_mutex_destroy(philos[i].L_fork);
		i++;
	}
	pthread_mutex_destroy(&philos->g_data->eat_lock);
	pthread_mutex_destroy(&philos->g_data->write_message);
	return (1);
}

int		check_kills(t_philo *philos)
{
	int	i;
	int	dies;

	dies = 0;
	printf("D\n");
	while (dies < philos->g_data->total_philos)
	{
		i = 0;
		dies = 0;
		//printf("D1\n");
		while (i < philos->g_data->total_philos)
		{
			//printf("D2\n");
			if (!philos[i].alive)
				dies++;
			i++;
			//printf("dies = %i\n", dies);
		}
		//printf("D3\n");
	}
    philos->g_data->condition = 1;
	return (1);
}

int survival(t_gdata *g_data, t_philo *philos)
{
    int i;

    g_data->time_begin = time_of_day();
    i = -1;
    while (++i < g_data->total_philos)
    {
		printf("h %i\n", i + 1);
        philos[i].time_last_meal = g_data->time_begin;
        if (pthread_create(&(philos[i].philo_thread), NULL, is_my_life, &philos[i]))
            return (1);
    }
	printf("b\n");
    //check_kills(philos);
	join_the_party(philos);
    printf("C\n");
    return (0);
}

int init_mutex(pthread_mutex_t **forks, t_gdata *g_data)
{
    int i;

    *forks = (pthread_mutex_t *)malloc(g_data->total_philos * sizeof(pthread_mutex_t));
    if (!(*forks))
	{
        return (0);
	}
    i = 0;
    printf("Total_filos = %ld\n", g_data->total_philos);
    while (i < g_data->total_philos)
    {
        if (pthread_mutex_init((*forks + i*sizeof(pthread_mutex_t)), NULL) != 0)
		{
            return(free(*forks), 0);
		}
        i++;
    }
    if (pthread_mutex_init(&(g_data->eat_lock), NULL) != 0)
            return(free(*forks), 0);
    if (pthread_mutex_init(&(g_data->write_message), NULL) != 0)
            return(free(*forks), 0);
    return (1);
}

int main(int argc, char *argv[])
{
    t_gdata             g_data;
    t_philo             *philos;
    pthread_mutex_t		*forks;

    if (!(argc >= 5 && argc <= 6))
	{
        printf("Invalid arguments...\n");
        return (0);
	}
    if (!are_right_values(argv, &g_data)) //se comprueba que los datos sean correctos.
    {
		return (0);
	}
    if (!init_mutex(&forks, &g_data))
    {
		return (0);
	}
	printf("a\n");
    if (!init_philos(&philos, &g_data, forks))
        return (free(forks), 0); //tener cuidado cuando haya 0 forks tenerlo controlao no vaya a dar seg f por liberar donde no debe
    survival(&g_data, philos);
    //finalization();
	printf("\nME FUIII!!!\n");
    return (free(forks), 0);

}
