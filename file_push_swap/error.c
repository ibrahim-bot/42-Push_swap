/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:29:00 by ibrahim           #+#    #+#             */
/*   Updated: 2021/03/05 13:54:01 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int     ft_error(char *str)
{
	ft_putstr(str);
	return (1);
}

int     check_num(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '-')
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_doublon(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_len(char **av)
{
	long long	t;
	int i;

	i = 0;
	while (av[i])
	{
		t = ft_atoi(av[i]);
		if (t > INT_MAX || t < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int     check_error(char **av)
{
	if (check_len(av) == 1)
		return (ft_error("Error: Value greater than an int.\n"));
	if (check_num(av) == 1)
		return (ft_error("Error: Use only numbers.\n"));
	if (check_doublon(av) == 1)
		return (ft_error("Error: Duplicate.\n"));
	return (0);
}
