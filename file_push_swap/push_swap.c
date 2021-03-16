/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:47 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/16 16:38:44 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		check_speed(t_elem *list)
{
	while (list->nxt != NULL)
	{
		if (list->val > list->nxt->val)
			return (1);
		list = list->nxt;
	}
	return (0);
}

void	first_check(t_elem *list)
{
	int		i;
	int		find;
	int		tmp;

	find = 1;
	tmp = list->val;
	while (find)
	{
		find = 0;
	 	i = 0;
		while (i < len_list(list))
		{
			if (tmp > list->val)
				tmp = list->val;
			i++;
			list = list->nxt;
			find = 1;
		}
	}
	printf("%d\n", tmp);
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
	if (check_speed(list_a) == 0)
		return (0);
	print_list(list_a);
	first_check(list_a);
	delet_list(&list_a);
	return (0);
}