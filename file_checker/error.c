/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:29:00 by ibrahim           #+#    #+#             */
/*   Updated: 2021/03/12 11:17:36 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_num(char **av, int cas)
{
	int i;
	int j;

	i = 1;
	if (cas == 1)
		i--;
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

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
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
	int			i;

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

int		check_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		check_error(int ac, char **av, t_check *check)
{
	if (ac < 2)
		return (ft_error("Error: ADD numbers\n"));
	if (av[2] == NULL && check_space(av[1]) == 1)
	{
		check->cas = 1;
		check->arg = ft_split(av[1], ' ');
		if (verif_error(check, av) == 1)
			return (1);
		return (0);
	}
	if (ft_l(av[1]) == 0)
		return (ft_error("Error: ADD numbers\n"));
	if (verif_error(check, av) == 1)
		return (1);
	return (0);
}
