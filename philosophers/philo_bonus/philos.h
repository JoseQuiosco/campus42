/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:32:40 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/08 16:39:10 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

typedef struct g_data
{
	long				total_philos;
	long				ttdie;
	long				tteat;
	long				ttsleep;
	long				total_must_eat;
	sem_t				*control_death;
	sem_t				*forks;
	sem_t				*write_message;
	sem_t				*control_eat;
	time_t				time_begin;
}	t_gdata;

typedef struct philo
{
	int					num;
	t_gdata				*g_data;
	time_t				time_last_meal;
	int					n_meals;
	pid_t				pid;

}	t_philo;

int		init_sems(t_gdata *g_data);
int		survival(t_gdata *g_data, t_philo *philos);
void	*check_kills(void *philo);
time_t	time_of_day(void);
void	*is_my_life(void *philo);
int		init_philos(t_philo **philos, t_gdata *g_data);
int		are_right_values(char **argv, t_gdata *g_data);
int		init_values(char **argv, int i, t_gdata *g_data);
long	ft_atoi(const char *str);
void	printing_message(t_philo *philo, const char *msg);
void	sleep_control(time_t t_sleep);
void	eat_fork(t_philo *philo);
void	obituary(t_philo *philo);

#endif
