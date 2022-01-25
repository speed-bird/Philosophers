/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:13:30 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:58:36 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*kill_philo(t_philo *philo)
{
	philo->dead = 1;
	philo->meal->ended = 1;
	print_status(philo, "died", 1);
	pthread_mutex_unlock(philo->frk_l);
	pthread_mutex_unlock(philo->frk_r);
	return (NULL);
}

void	*checker(void *meal)
{
	t_meal	*m;
	int		i;
	int		p_satiated;

	m = meal;
	while (!m->ended)
	{
		i = 0;
		p_satiated = 0;
		while (i < m->pop)
		{
			if (get_time() - m->philos[i].time_lsm > m->ttd)
				return (kill_philo(&m->philos[i]));
			if (m->min_meals && m->philos[i].meals_amount >= m->min_meals)
				p_satiated++;
			i++;
		}
		if (p_satiated == m->pop)
		{	
			m->ended = 1;
			return (NULL);
		}
	}
	return (NULL);
}
