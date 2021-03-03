/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:43:13 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/03 16:36:39 by ichougra         ###   ########lyon.fr   */
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
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_doublon
int     check_error(int ac, char **av)
{
	if (ac < 2)
		return (ft_error("Error: ADD nb\n"));
	if (check_num(av) == 1)
		return (ft_error("Error: use only numbers\n"));
	return (0);
}

int main(int ac, char **av)
{
	if (check_error(ac, av) == 1)
		return (1);
	return (0);
}