/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:32:40 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/02 20:36:19 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

/*
typedef struct s_philo {
	int					number;
	pthread_t			philo_thread;
	int					left_fork;
	int					right_fork;
	struct s_data		*data;
	time_t				last_time_ate;
	int					n_of_meals;
}	t_philo;

typedef struct s_data {
	long				n_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				times_must_eat;
	int					death_check;
	int					all_ate;
	time_t				start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_message;
	pthread_mutex_t		eat_lock;
	t_philo				*philo;
}	t_data;
*/

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
	time_t				time_begin;
}   t_gdata;

typedef struct philo
{
    int					num;
	pthread_t			philo_thread;
	t_gdata             *g_data;
    pthread_mutex_t  	*L_fork;
	pthread_mutex_t		*R_fork;
	pthread_mutex_t		philock;
	time_t				time_last_meal;
	int					n_meals;
	int					alive;


}   t_philo;


int init_mutex(pthread_mutex_t **forks, t_gdata *g_data);
int survival(t_gdata *g_data, t_philo *philos);
int		check_kills(t_philo *philos);
int		join_the_party(t_philo	*philos);
time_t	time_of_day(void);
void	*is_my_life(void *philo);
int		print_locked(t_philo *philo);
int 	init_philos(t_philo **philos, t_gdata *g_data, pthread_mutex_t  *forks);
int 	are_right_values(char **argv, t_gdata *g_data);
void    init_values(char **argv, int i, t_gdata *g_data);
long	ft_atoi(const char *str);
