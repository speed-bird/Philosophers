/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:21:06 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:37:26 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fail(char *error_txt)
{
	printf("Error - [%s]\n", error_txt);
	return (1);
}

int	clear_all(t_meal *meal)
{
	while (meal->pop--)
		pthread_mutex_destroy(&meal->forks[meal->pop]);
	pthread_mutex_destroy(&meal->print);
	if (meal->forks)
		free(meal->forks);
	if (meal->philos)
		free(meal->philos);
	if (meal->threads)
		free(meal->threads);
	return (1);
}
