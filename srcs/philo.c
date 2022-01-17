/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:43:57 by jrobert           #+#    #+#             */
/*   Updated: 2022/01/17 12:57:16 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
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

void error(char *error_txt)
{
	write(2, error_txt, ft_strlen(error_txt));
}

void	parse_args(t_status *status, int argc, char **argv)
{
	status->pop = ft_atoi(argv[1]);
	status->ttd = ft_atoi(argv[2]);
	status->tte = ft_atoi(argv[3]);
	status->tts = ft_atoi(argv[4]);
	if (argc == 6)
		status->min_meals = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_status	status;

	status = (t_status){};
	if (argc < 5 || argc > 6)
		error("Invalid number of args\n");
	else
		parse_args(&status, argc, argv);
	return (0);
}
