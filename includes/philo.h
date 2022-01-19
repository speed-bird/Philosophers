/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:43:54 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/18 18:39:55 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_meal
{
	int			ttd;
	int			tte;
	int			tts;
	int			pop;
	int			min_meals;
	int			dead;
	pthread_t	*threads;
}				t_meal;

void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_is_nbr(char *str);
int		ft_atoi(const char *str);

#endif
