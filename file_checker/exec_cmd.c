/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:56:41 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/11 16:46:06 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_sa_sb(t_elem **list)
{
	int	tmp;

	if (*list == NULL || len_list(*list) == 1)
		return ;
	tmp = 0;
	tmp = (*list)->val;
	(*list)->val = (*list)->nxt->val;
	(*list)->nxt->val = tmp;
}

void	exec_ss(t_elem **list_a, t_elem **list_b)
{
	exec_sa_sb(list_a);
	exec_sa_sb(list_b);
}

void	exec_pa(t_elem **list_a, t_elem **list_b)
{
	if (*list_b == NULL)
		return ;
	add_front(list_a, (*list_b)->val);
	del_list_front(list_b);
}

void	exec_pb(t_elem **list_a, t_elem **list_b)
{
	if (*list_a == NULL)
		return ;
	add_front(list_b, (*list_a)->val);
	del_list_front(list_a);
}

void	exec_ra_rb(t_elem **list)
{
	if (*list == NULL)
		return ;
	add_end(list, (*list)->val);
	del_list_front(list);
}
