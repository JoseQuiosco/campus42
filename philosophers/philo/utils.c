/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:14:30 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/08/07 21:31:30 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

long	ft_atoi(const char *str)
{
	int		sign;
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

void	printing_message(t_philo *philo, const char *msg)
{
	long	time;

	pthread_mutex_lock(&philo->g_data->write_message);
	pthread_mutex_lock(&philo->g_data->check_death);
	time = (long)(time_of_day() - philo->g_data->time_begin);
	if (!philo->g_data->a_death && !philo->g_data->all_sated)
	{
		printf("%lu %d %s\n", time, philo->num, msg);
	}
	pthread_mutex_unlock(&philo->g_data->check_death);
	pthread_mutex_unlock(&philo->g_data->write_message);
}

void	sleep_control(t_philo *philo, time_t t_sleep)
{
	time_t	start;

	start = time_of_day();
	while (1)
	{
		pthread_mutex_lock(&philo->g_data->check_death);
		if (philo->g_data->a_death || philo->g_data->all_sated)
		{
			pthread_mutex_unlock(&philo->g_data->check_death);
			break ;
		}
		pthread_mutex_unlock(&philo->g_data->check_death);
		if ((time_of_day() - start) >= t_sleep)
			break ;
		usleep(50);
	}
}

time_t	time_of_day(void)
{
	struct timeval	timer;

	if (gettimeofday(&timer, NULL))
		return (0);
	return (timer.tv_sec * 1000 + timer.tv_usec / 1000);
}

void	obituary(t_philo *philo)
{
	pthread_mutex_lock(&philo->g_data->write_message);
	printf("%ld %i died\n", (time_of_day()
			- philo->g_data->time_begin), philo->num);
	pthread_mutex_unlock(&philo->g_data->write_message);
	pthread_mutex_lock(&philo->g_data->check_death);
	philo->g_data->a_death = 1;
	pthread_mutex_unlock(&philo->g_data->check_death);
	pthread_mutex_unlock(&philo->philock);
}
