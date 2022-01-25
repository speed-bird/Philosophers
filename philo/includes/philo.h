/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:43:54 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:32:55 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_meal	t_meal;

typedef struct s_philo
{	
	int					id;
	int					meals_amount;
	int					dead;
	time_t				time_lsm;
	t_meal				*meal;
	pthread_mutex_t		*frk_l;
	pthread_mutex_t		*frk_r;
}				t_philo;

typedef struct s_meal
{
	int					ttd;
	int					tte;
	int					tts;
	int					pop;
	int					min_meals;
	int					dead;
	int					ended;
	time_t				time_sm;
	pthread_t			*threads;
	pthread_t			checker;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
}					t_meal;

void	*kill_philo(t_philo *philo);
void	*checker(void *meal);
int		fail(char *error_txt);
int		clear_all(t_meal *meal);
int		join_threads(t_meal *meal);
int		init_threads(t_meal *meal);
int		init_mutexes(t_meal *meal);
int		init_philos(t_meal *meal);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleeep(t_philo *philo);
void	think(t_philo *philo);
void	*life(void *philo);
void	parse_args(t_meal *meal, int argc, char **argv);
int		valid_args(int argc, char **argv);
void	print_status(t_philo *philo, char *action_txt, int killed);
void	my_sleep(time_t duration);
time_t	get_time(void);
int		ft_atoi(const char *str);
int		ft_is_nbr(char *str);

#endif
