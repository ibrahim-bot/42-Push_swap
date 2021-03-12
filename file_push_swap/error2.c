/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:50:19 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/12 11:01:47 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_error(char *str)
{
	ft_putstr(str);
	return (1);
}

int		verif_error(t_check *check, char **av)
{
	if (check->cas == 1)
	{
		if (check->arg[0] == NULL)
			return (1);
		if (check_len(check->arg) == 1)
			return (ft_error("Error: Value greater than an int.\n"));
		if (check_num(check->arg, check->cas) == 1)
			return (ft_error("Error: Use only numbers.\n"));
		if (check_doublon(check->arg) == 1)
			return (ft_error("Error: Duplicate.\n"));
	}
	else
	{
		if (check_len(av) == 1)
			return (ft_error("Error: Value greater than an int.\n"));
		if (check_num(av, 0) == 1)
			return (ft_error("Error: Use only numbers.\n"));
		if (check_doublon(av) == 1)
			return (ft_error("Error: Duplicate.\n"));
	}
	return (0);
}

int		parsing(char *buffer)
{
	if (strcmp(buffer, "sa") && strcmp(buffer, "sb") && strcmp(buffer, "ss") &&
		strcmp(buffer, "pa") && strcmp(buffer, "pb") && strcmp(buffer, "ra") &&
		strcmp(buffer, "rb") && strcmp(buffer, "rr") && strcmp(buffer, "rra")
		&& strcmp(buffer, "rrb") && strcmp(buffer, "rrr"))
		return (1);
	return (0);
}
