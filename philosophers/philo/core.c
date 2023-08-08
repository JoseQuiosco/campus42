/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:11:42 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/07 22:14:29 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	eat_l_fork_first(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printing_message(philo, "has taken a fork");
	if (philo->g_data->total_philos == 1)
	{
		sleep_control(philo, philo->g_data->ttdie + 100);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	printing_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->philock);
	printing_message(philo, "is eating");
	philo->time_last_meal = time_of_day();
	philo->n_meals += 1;
	pthread_mutex_unlock(&philo->philock);
	sleep_control(philo, philo->g_data->tteat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	eat_r_fork_first(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printing_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	printing_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->philock);
	printing_message(philo, "is eating");
	philo->time_last_meal = time_of_day();
	philo->n_meals += 1;
	pthread_mutex_unlock(&philo->philock);
	sleep_control(philo, philo->g_data->tteat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*is_my_life(void *philo)
{
	t_philo	*filo;

	filo = (t_philo *)philo;
	while (1)
	{
		if (filo->num % 2)
			eat_l_fork_first((t_philo *)philo);
		else
			eat_r_fork_first((t_philo *)philo);
		printing_message(philo, "is sleeping");
		sleep_control(philo, filo->g_data->ttsleep);
		printing_message(philo, "is thinking");
		pthread_mutex_lock(&filo->g_data->check_death);
		if (filo->g_data->a_death || filo->g_data->all_sated)
		{
			pthread_mutex_unlock(&filo->g_data->check_death);
			break ;
		}
		pthread_mutex_unlock(&filo->g_data->check_death);
	}
	return (NULL);
}

int	join_the_party(t_philo *philos)
{
	int	i;
	int	total_philos;

	i = 0;
	total_philos = philos[0].g_data->total_philos;
	while (i < total_philos)
	{
		pthread_join(philos[i].philo_thread, NULL);
		i++;
	}
	i = 0;
	while (i < total_philos)
	{
		pthread_mutex_destroy(philos[i].l_fork);
		pthread_mutex_destroy(&philos[i].philock);
		i++;
	}
	pthread_mutex_destroy(&philos->g_data->write_message);
	return (1);
}

int	check_kills(t_philo *philos, int i, int j)
{
	while (1)
	{
		i = -1;
		j = 0;
		while (++i < philos->g_data->total_philos)
		{
			pthread_mutex_lock(&philos[i].philock);
			if ((time_of_day() - philos[i].time_last_meal)
				>= philos->g_data->ttdie)
				return (obituary(&philos[i]), 0);
			if (philos->g_data->total_must_eat > 0
				&& philos[i].n_meals >= philos->g_data->total_must_eat)
				j++;
			pthread_mutex_unlock(&philos[i].philock);
			usleep(100);
		}
		if (j == philos->g_data->total_philos)
		{
			pthread_mutex_lock(&philos->g_data->check_death);
			philos->g_data->all_sated = 1;
			pthread_mutex_unlock(&philos->g_data->check_death);
			break ;
		}
	}
	return (1);
}
