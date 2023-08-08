/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:41:35 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/08 17:06:55 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	ft_freedom(t_gdata *g_data, t_philo *philos)
{
	sem_unlink("writing");
	sem_close(g_data->write_message);
	sem_unlink("forks");
	sem_close(g_data->forks);
	sem_post(g_data->control_death);
	sem_unlink("control_death");
	sem_close(g_data->control_death);
	if (philos)
		free(philos);
}

int	main(int argc, char *argv[])
{
	t_gdata			g_data;
	t_philo			*philos;

	if (!(argc >= 5 && argc <= 6))
	{
		printf("Invalid arguments...\n");
		return (0);
	}
	if (!are_right_values(argv, &g_data))
		return (0);
	if (!init_sems(&g_data))
		return (0);
	philos = NULL;
	if (!init_philos(&philos, &g_data))
		return (ft_freedom(&g_data, philos), 0);
	survival(&g_data, philos);
	ft_freedom(&g_data, philos);
	return (0);
}
