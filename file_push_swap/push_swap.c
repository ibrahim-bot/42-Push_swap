/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:47 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/17 00:09:17 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		check_tri(t_elem *list)
{
	while (list->nxt != NULL)
	{
		if (list->val > list->nxt->val)
			return (1);
		list = list->nxt;
	}
	return (0);
}

int		check_speed(t_elem *list)
{
	if (len_list(list) == 2)
	{
		if (list->val > list->nxt->val)
			ft_putstr("sa\n");
		return (0);
	}
	while (list->nxt != NULL)
	{
		if (list->val > list->nxt->val)
			return (1);
		list = list->nxt;
	}
	return (0);
}

int		search_lit(t_elem *list)
{
	int		i;
	int		j;
	int		tmp;
	t_elem	*dtmp;

	tmp = list->val;
	dtmp = list;
	i = 0;
	j = len_list(list);
	while (i < j)
	{
		if (list->val < tmp)
			tmp = list->val;
		i++;
		list = list->nxt;
	}
	i = 0;
	j = tmp;
	while (dtmp->val != j)
	{
		i++;
		dtmp = dtmp->nxt;
	}
	return (i + 1);
}

void	check_list2(t_elem **list, t_elem **list2)
{
	int j;

	j = len_list(*list2);
	while (j > 0)
	{
		exec_pa(list, list2);
		ft_putstr("pa\n");
		j--;
	}
	if (check_list(*list) != 1)
		delet_list(list2);
}

void	first_check(t_elem **list, t_elem **list2)
{
	while (42)
	{
		if (check_tri(*list) == 0)
		{
			check_list2(list, list2);
			return ;
		}
		else if (search_lit(*list) == 1)
		{
			exec_pb(list, list2);
			ft_putstr("pb\n");
		}
		else if (search_lit(*list) == 2)
		{
			exec_sa_sb(list);
			ft_putstr("sa\n");
		}
		else if (search_lit(*list) == len_list(*list))
		{
			exec_rra_rrb(list);
			ft_putstr("rra\n");
		}
		else 
		{
			exec_ra_rb(list);
			ft_putstr("ra\n");
		}
		
	}
}

int		main(int ac, char **av)
{
	t_elem	*list_a;
	t_elem	*list_b;
	t_check	check;

	list_a = NULL;
	list_b = NULL;
	check.cas = 0;
	if (check_error(ac, av, &check) == 1)
		return (1);
	if (check.cas == 1)
		fill_list(&list_a, check.arg);
	else
		fill_list(&list_a, av);
	if (check_speed(list_a) == 0)
	{
		delet_list(&list_a);
		return (0);
	}
	print_list(list_a);
	first_check(&list_a, &list_b);
	print_list(list_a);
	delet_list(&list_a);
	return (0);
}