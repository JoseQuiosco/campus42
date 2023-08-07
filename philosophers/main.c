/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:41:35 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/03 17:55:56 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char *argv[])
{
	t_gdata			g_data;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (!(argc >= 5 && argc <= 6))
	{
		printf("Invalid arguments...\n");
		return (0);
	}
	if (!are_right_values(argv, &g_data))
		return (0);
	if (!init_mutex(&forks, &g_data))
		return (0);
	if (!init_philos(&philos, &g_data, forks))
		return (free(forks), 0);
	survival(&g_data, philos);
	return (free(forks), free(philos), 0);
}
