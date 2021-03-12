/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:43:13 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/12 16:39:07 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		last_check(t_elem *list_a, t_elem *list_b)
{
	t_elem *tmp;

	if (check_list(list_b) == 0 || check_list(list_a) == 1)
	{
		delet_list(&list_b);
		return (1);
	}
	tmp = list_a;
	while (tmp->nxt != NULL)
	{
		if (tmp->val > tmp->nxt->val)
			return (1);
		tmp = tmp->nxt;
	}
	delet_list(&list_a);
	return (0);
}

void	stock_buffer(t_check *check, char *buffer)
{
	if (check->str == NULL)
		check->str = malloc(sizeof(char) * 4086);
	strcat(check->str, buffer);
	strcat(check->str, "@");
}

int		loop_gen(t_check *check)
{
	char	*buffer;

	while (get_next_line(0, &buffer) > 0)
	{
		if (ft_l(buffer) == 0)
		{
			free(buffer);
			return (0); 
		}
		if (parsing(buffer) == 1)
		{
			free(buffer);
			return (ft_error("Error: Command not found\n"));
		}
		stock_buffer(check, buffer);
		free(buffer);
	}
	free(buffer);
	return (0);
}

int		main(int ac, char **av)
{
	t_elem	*list_a;
	t_elem	*list_b;
	t_check	check;

	list_a = NULL;
	list_b = NULL;
	if (check_error(ac, av, &check) == 1)
		return (1);
	if (check.cas == 1)
		fill_list(&list_a, check.arg);
	else
		fill_list(&list_a, av);
	if (loop_gen(&check) == 1)
		return (1);
	tri_list(&list_a, &list_b, &check);
	if (last_check(list_a, list_b) == 0)
		return (ft_error("OK\n"));
	ft_putstr("KO\n");
	return (0);
}
