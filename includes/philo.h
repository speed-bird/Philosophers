/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:43:54 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/17 12:41:05 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

typedef struct s_status
{
	int ttd;
	int	tte;
	int	tts;
	int	pop;
	int	min_meals;
}				t_status;

#endif