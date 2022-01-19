/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:43:57 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/18 20:41:05 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *error_txt)
{
	ft_putstr_fd("Error - [", 2);
	ft_putstr_fd(error_txt, 2);
	ft_putstr_fd("]\n", 2);
	return (EXIT_FAILURE);
}

void	parse_args(t_meal *meal, int argc, char **argv)
{
	meal->pop = ft_atoi(argv[1]);
	meal->ttd = ft_atoi(argv[2]);
	meal->tte = ft_atoi(argv[3]);
	meal->tts = ft_atoi(argv[4]);
	if (argc == 6)
		meal->min_meals = ft_atoi(argv[5]);
}

void	take_fork(int pid)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	ft_putnbr_fd(tv.tv_sec, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" has taken a fork\n", 1);
}

void	eat(int pid)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	ft_putnbr_fd(tv.tv_sec, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" is eating\n", 1);
}

void	*life(void *arg)
{
	int	pid;

	pid = *((int *)arg);
	take_fork(pid);
	take_fork(pid);
	eat(pid);
	return (NULL);
}

int	init_threads(t_meal *meal)
{
	int	pid;
	int	err;

	meal->threads = (pthread_t *)malloc(sizeof(pthread_t) * meal->pop);
	if (!meal->threads)
		return (0);
	pid = 0;
	while (pid++ < meal->pop)
	{
		err = pthread_create(&meal->threads[pid], NULL, &life, &pid);
		if (err)
		{
			free(meal->threads);
			error("Thread creation failed");
			return (0);
		}
		pthread_join(meal->threads[pid], NULL);
	}
	return (1);
}

int	valid_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	i = 0;
	while (++i < argc)
		if (!ft_is_nbr(argv[i]) || !ft_atoi(argv[i]) || ft_atoi(argv[i]) < 1)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_meal	meal;

	meal = (t_meal){};
	if (!valid_args(argc, argv))
		return (error("Invalid args"));
	parse_args(&meal, argc, argv);
	init_threads(&meal);
	return (0);
}
