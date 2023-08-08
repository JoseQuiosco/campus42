/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:03:09 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/07 22:17:55 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	init_values(char **argv, int i, t_gdata *g_data)
{
	if (i == 1)
		g_data->total_philos = ft_atoi(argv[i]);
	if (g_data->total_philos == 0)
		return (0);
	if (i == 2)
		g_data->ttdie = ft_atoi(argv[i]);
	if (i == 3)
		g_data->tteat = ft_atoi(argv[i]);
	if (i == 4)
		g_data->ttsleep = ft_atoi(argv[i]);
	if (i == 5)
		g_data->total_must_eat = ft_atoi(argv[i]);
	if (g_data->total_must_eat == 0)
		return (0);
	g_data->all_sated = 0;
	g_data->a_death = 0;
	return (1);
}

int	init_philos(t_philo **philos, t_gdata *g_data, pthread_mutex_t *forks)
{
	int	i;

	*philos = (t_philo *)malloc(g_data->total_philos * sizeof(t_philo));
	if (!(*philos))
		return (0);
	i = 0;
	while (i < g_data->total_philos)
	{
		(*philos + i)->num = i + 1;
		(*philos + i)->time_last_meal = 0;
		(*philos + i)->n_meals = 0;
		(*philos + i)->g_data = g_data;
		(*philos + i)->l_fork = &forks[i];
		if (i == g_data->total_philos - 1)
			(*philos + i)->r_fork = &forks[0];
		else
			(*philos + i)->r_fork = &forks[i + 1];
		if (pthread_mutex_init(&(*philos + i)->philock, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_mutex(pthread_mutex_t **forks, t_gdata *g_data)
{
	int	i;
	int	total_philos;

	total_philos = g_data->total_philos;
	*forks = (pthread_mutex_t *)malloc(total_philos * sizeof(pthread_mutex_t));
	if (!(*forks))
	{
		return (0);
	}
	i = 0;
	while (i < g_data->total_philos)
	{
		if (pthread_mutex_init((*forks + i), NULL) != 0)
		{
			return (free(*forks), 0);
		}
		i++;
	}
	if (pthread_mutex_init(&(g_data->write_message), NULL) != 0)
		return (free(*forks), 0);
	if (pthread_mutex_init(&(g_data->check_death), NULL) != 0)
		return (free(*forks), 0);
	return (1);
}

int	are_right_values(char **argv, t_gdata *g_data)
{
	int	i;
	int	j;

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
		if (!init_values(argv, i, g_data))
			return (0);
		i++;
	}
	if (i == 5)
		g_data->total_must_eat = -1;
	return (1);
}

int	survival(t_gdata *g_data, t_philo *philos)
{
	int	i;

	g_data->time_begin = time_of_day();
	i = -1;
	while (++i < g_data->total_philos)
	{
		philos[i].time_last_meal = g_data->time_begin;
		if (pthread_create(&(philos[i].philo_thread), NULL,
				is_my_life, &philos[i]))
			return (1);
	}
	check_kills(philos, 0, 0);
	join_the_party(philos);
	return (0);
}
