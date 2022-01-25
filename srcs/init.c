/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:26:35 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:15:52 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_meal *meal)
{
	int	i;
	int	err;

	i = 0;
	while (i < meal->pop)
	{
		err = pthread_join(meal->threads[i++], NULL);
		if (err)
			return (0);
	}
	err = pthread_join(meal->checker, NULL);
	if (err)
		return (0);
	return (1);
}

int	init_threads(t_meal *meal)
{
	int	i;
	int	err;

	meal->threads = (pthread_t *)malloc(sizeof(pthread_t) * meal->pop);
	if (!meal->threads)
		return (0);
	i = -1;
	while (++i < meal->pop)
	{
		err = pthread_create(&meal->threads[i], NULL,
				&life, (void *)&meal->philos[i]);
		if (err)
			return (0);
	}
	err = pthread_create(&meal->checker, NULL,
			&checker, (void *)meal);
	if (err)
		return (0);
	if (!join_threads(meal))
		return (0);
	return (1);
}

int	init_mutexes(t_meal *meal)
{
	int	i;
	int	err;

	meal->forks = malloc(sizeof(pthread_mutex_t) * meal->pop);
	if (!meal->forks)
		return (0);
	i = -1;
	while (++i < meal->pop)
	{
		err = pthread_mutex_init(&meal->forks[i], NULL);
		if (err)
			return (0);
	}
	err = pthread_mutex_init(&meal->print, NULL);
	if (err)
		return (0);
	return (1);
}

int	init_philos(t_meal *meal)
{
	int	i;

	meal->philos = (t_philo *)malloc(sizeof(t_philo) * meal->pop);
	if (!meal->philos)
		return (0);
	i = -1;
	while (++i < meal->pop)
	{
		meal->philos[i].meal = meal;
		meal->philos[i].meals_amount = 0;
		meal->philos[i].dead = 0;
		meal->philos[i].frk_l = &meal->forks[i];
		meal->philos[i].frk_r = &meal->forks[(i + 1) % meal->pop];
		meal->time_sm = get_time();
		meal->philos[i].time_lsm = get_time();
		meal->philos[i].id = i;
	}
	return (1);
}
