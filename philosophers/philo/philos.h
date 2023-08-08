/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:32:40 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/07 22:15:50 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct g_data
{
	long				total_philos;
	long				ttdie;
	long				tteat;
	long				ttsleep;
	long				total_must_eat;
	int					all_sated;
	int					condition;
	int					a_death;
	pthread_mutex_t		write_message;
	pthread_mutex_t		check_death;
	time_t				time_begin;
}	t_gdata;

typedef struct philo
{
	int					num;
	pthread_t			philo_thread;
	t_gdata				*g_data;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		philock;
	time_t				time_last_meal;
	int					n_meals;
}	t_philo;

int		init_mutex(pthread_mutex_t **forks, t_gdata *g_data);
int		survival(t_gdata *g_data, t_philo *philos);
int		check_kills(t_philo *philos, int i, int j);
int		join_the_party(t_philo	*philos);
time_t	time_of_day(void);
void	*is_my_life(void *philo);
int		print_locked(t_philo *philo);
int		init_philos(t_philo **philos, t_gdata *g_data, pthread_mutex_t *forks);
int		are_right_values(char **argv, t_gdata *g_data);
int		init_values(char **argv, int i, t_gdata *g_data);
long	ft_atoi(const char *str);
void	printing_message(t_philo *philo, const char *msg);
void	sleep_control(t_philo *philo, time_t t_sleep);
void	eat_l_fork_first(t_philo *philo);
void	eat_r_fork_first(t_philo *philo);
void	obituary(t_philo *philo);

#endif