/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:47:00 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:16:59 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0 && philo->id + 1 < philo->meal->pop)
	{	
		pthread_mutex_lock(philo->frk_r);
		print_status(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->frk_l);
		print_status(philo, "has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(philo->frk_l);
		print_status(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->frk_r);
		print_status(philo, "has taken a fork", 0);
	}
}

void	eat(t_philo *philo)
{
	philo->time_lsm = get_time();
	print_status(philo, "is eating", 0);
	philo->meals_amount++;
	my_sleep(philo->meal->tte);
	pthread_mutex_unlock(philo->frk_l);
	pthread_mutex_unlock(philo->frk_r);
}

void	sleeep(t_philo *philo)
{
	print_status(philo, "is sleeping", 0);
	my_sleep(philo->meal->tts);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking", 0);
}

void	*life(void *philo)
{
	t_philo	*p;

	p = philo;
	while (!p->meal->ended)
	{
		take_forks(p);
		if (p->meal->ended)
			return (NULL);
		eat(p);
		if (p->meal->ended)
			return (NULL);
		sleeep(p);
		if (p->meal->ended)
			return (NULL);
		think(p);
	}
	return (NULL);
}
