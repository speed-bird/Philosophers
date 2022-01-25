/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:14:26 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:58:21 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *action_txt, int killed)
{
	if (!philo->meal->ended || killed)
	{
		pthread_mutex_lock(&philo->meal->print);
		printf("%ld %d %s\n", get_time() - philo->meal->time_sm,
			philo->id + 1, action_txt);
		pthread_mutex_unlock(&philo->meal->print);
	}
}

void	my_sleep(time_t duration)
{
	time_t	time;

	time = get_time();
	usleep(duration * 900);
	while (get_time() < time + duration)
	{
		usleep(10);
	}
}

time_t	get_time(void)
{
	time_t			t;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	t = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (t);
}

int	ft_atoi(const char *str)
{
	long unsigned	val;
	long unsigned	limit;
	int				sign;

	val = 0;
	limit = 922337203685477580;
	sign = 1;
	while (*str == 32 || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && val < limit)
		val = val * 10 + *str++ - 48;
	if (val == limit && ((sign == 1 && *str <= '7')
			|| (sign == -1 && *str <= '8')))
		val = val * 10 + *str - 48;
	else if (val >= limit && sign == 1)
		return (-1);
	else if (val >= limit && sign == -1)
		return (0);
	return (sign * val);
}

int	ft_is_nbr(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
