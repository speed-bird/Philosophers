/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:43:57 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/25 18:58:07 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parse_args(t_meal *meal, int argc, char **argv)
{
	meal->pop = ft_atoi(argv[1]);
	meal->ttd = ft_atoi(argv[2]);
	meal->tte = ft_atoi(argv[3]);
	meal->tts = ft_atoi(argv[4]);
	if (argc == 6)
		meal->min_meals = ft_atoi(argv[5]);
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
		return (fail("Invalid args"));
	parse_args(&meal, argc, argv);
	if (!init_mutexes(&meal))
		return (fail("Mutex creation failed") && clear_all(&meal));
	if (!init_philos(&meal))
		return (fail("Mutex creation failed") && clear_all(&meal));
	if (!init_threads(&meal))
		return (fail("Thread creation failed") && clear_all(&meal));
	clear_all(&meal);
	return (0);
}
