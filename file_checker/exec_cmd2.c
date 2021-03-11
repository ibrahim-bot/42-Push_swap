/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:59:05 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/11 16:48:08 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_rr(t_elem **list_a, t_elem **list_b)
{
	exec_ra_rb(list_a);
	exec_ra_rb(list_b);
}

void	exec_rra_rrb(t_elem **list)
{
	t_elem	*tmp;
	int		val;

	val = 0;
	if (*list == NULL)
		return ;
	tmp = *list;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	val = tmp->val;
	add_front(list, val);
	del_list_end(list);
}

void	exec_rrr(t_elem **list_a, t_elem **list_b)
{
	exec_rra_rrb(list_a);
	exec_rra_rrb(list_b);
}
