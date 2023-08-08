/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:03:09 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/08 17:01:44 by dvasco-m         ###   ########.fr       */
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
	return (1);
}

int	init_philos(t_philo **philos, t_gdata *g_data)
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
		(*philos + i)->pid = -1;
		i++;
	}
	return (1);
}

void	save_sem_close(t_gdata *g_data)
{
	sem_unlink("writing");
	sem_close(g_data->write_message);
	sem_unlink("control_death");
	sem_close(g_data->control_death);
}

int	init_sems(t_gdata *g_data)
{
	sem_unlink("writing");
	g_data->write_message = sem_open("writing", O_CREAT, 0600, 1);
	if (g_data->write_message == SEM_FAILED)
		return (0);
	sem_unlink("forks");
	g_data->forks = sem_open("forks", O_CREAT, 0600, g_data->total_philos);
	if (g_data->forks == SEM_FAILED)
		return (sem_unlink("writing"), sem_close(g_data->write_message), 0);
	sem_unlink("control_death");
	g_data->control_death = sem_open("control_death", O_CREAT, 0600, 1);
	if (g_data->control_death == SEM_FAILED)
	{
		sem_unlink("writing");
		sem_close(g_data->write_message);
		return (sem_unlink("forks"), sem_close(g_data->forks), 0);
	}
	sem_unlink("control_eat");
	g_data->control_eat = sem_open("control_eat", O_CREAT, 0600, 1);
	if (g_data->control_eat == SEM_FAILED)
	{
		save_sem_close(g_data);
		return (sem_unlink("forks"), sem_close(g_data->forks), 0);
	}
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
