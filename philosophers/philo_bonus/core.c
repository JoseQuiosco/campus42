/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:11:42 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/08 17:11:22 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	eat_fork(t_philo *philo)
{
	sem_wait(philo->g_data->forks);
	printing_message(philo, "has taken a fork");
	if (philo->g_data->total_philos == 1)
	{
		sleep_control(philo->g_data->ttdie + 100);
		return ;
	}
	sem_wait(philo->g_data->forks);
	printing_message(philo, "has taken a fork");
	printing_message(philo, "is eating");
	sem_wait(philo->g_data->control_eat);
	philo->time_last_meal = time_of_day();
	philo->n_meals += 1;
	sem_post(philo->g_data->control_eat);
	sleep_control(philo->g_data->tteat);
	sem_post(philo->g_data->forks);
	sem_post(philo->g_data->forks);
}

void	*is_my_life(void *philo)
{
	t_philo		*filo;
	pthread_t	thread;

	filo = (t_philo *)philo;
	pthread_create(&thread, NULL, check_kills, filo);
	pthread_detach(thread);
	while (1)
	{
		eat_fork((t_philo *)philo);
		printing_message(philo, "is sleeping");
		sleep_control(filo->g_data->ttsleep);
		printing_message(philo, "is thinking");
	}
	return (NULL);
}

void	*check_kills(void *philo)
{
	t_philo	*filo;

	filo = (t_philo *)philo;
	while (1)
	{
		sem_wait(filo->g_data->control_eat);
		if ((time_of_day() - filo->time_last_meal)
			>= filo->g_data->ttdie)
		{
			return (obituary(filo), NULL);
		}
		if (filo->g_data->total_must_eat > 0
			&& filo->n_meals >= filo->g_data->total_must_eat)
		{
			sem_post(filo->g_data->control_eat);
			sem_post(filo->g_data->forks);
			sem_post(filo->g_data->forks);
			exit(0);
		}
		sem_post(filo->g_data->control_eat);
		usleep(50);
	}
	return (NULL);
}

void	*kill_them_all(void *philos)
{
	int		i;
	int		total_philos;
	t_philo	*filos;

	filos = (t_philo *)philos;
	i = 0;
	total_philos = filos->g_data->total_philos;
	sem_wait(filos->g_data->control_death);
	while (i < total_philos)
	{
		kill(filos[i].pid, SIGKILL);
		i++;
	}
	return (NULL);
}

int	survival(t_gdata *g_data, t_philo *philos)
{
	int			i;
	pthread_t	thread;

	g_data->time_begin = time_of_day();
	i = -1;
	sem_wait(philos->g_data->control_death);
	while (++i < g_data->total_philos)
	{
		philos[i].time_last_meal = g_data->time_begin;
		philos[i].pid = fork();
		if (philos[i].pid == 0)
		{
			is_my_life(&philos[i]);
			exit(0);
		}
		usleep(100);
	}
	pthread_create(&thread, NULL, kill_them_all, philos);
	pthread_detach(thread);
	i = 0;
	while (i++ < g_data->total_philos)
		waitpid(-1, NULL, 0);
	return (0);
}
