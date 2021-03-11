/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:56:10 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/11 16:50:53 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	tri_list_s(t_elem **list_a, t_elem **list_b, t_check *check, int *i)
{
	if (check->str[*i] == 'r' && check->str[*i + 1] == 'a')
		exec_ra_rb(list_a);
	else if (check->str[*i] == 'r' && check->str[*i + 1] == 'b')
		exec_ra_rb(list_b);
	else if (check->str[*i] == 'r' && check->str[*i + 1] == 'r'
	&& check->str[*i + 2] == '@')
		exec_rr(list_a, list_b);
	else if (check->str[*i] == 'r' && check->str[*i + 1] == 'r'
	&& check->str[*i + 2] == 'a')
	{
		exec_rra_rrb(list_a);
		*i = *i + 1;
	}
	else if (check->str[*i] == 'r' && check->str[*i + 1] == 'r'
	&& check->str[*i + 2] == 'b')
	{
		exec_rra_rrb(list_b);
		*i = *i + 1;
	}
	else if (check->str[*i] == 'r' && check->str[*i + 1] == 'r'
	&& check->str[*i + 2] == 'r')
	{
		exec_rrr(list_a, list_b);
		*i = *i + 1;
	}
}

void	tri_list(t_elem **list_a, t_elem **list_b, t_check *check)
{
	int	i;

	i = 0;
	if (len_list(*list_a) == 1 || check->str == NULL)
		return ;
	while (check->str[i])
	{
		if (check->str[i] == 's' && check->str[i + 1] == 'a')
			exec_sa_sb(list_a);
		else if (check->str[i] == 's' && check->str[i + 1] == 'b')
			exec_sa_sb(list_b);
		else if (check->str[i] == 's' && check->str[i + 1] == 's')
			exec_ss(list_a, list_b);
		else if (check->str[i] == 'p' && check->str[i + 1] == 'a')
			exec_pa(list_a, list_b);
		else if (check->str[i] == 'p' && check->str[i + 1] == 'b')
			exec_pb(list_a, list_b);
		tri_list_s(list_a, list_b, check, &i);
		i++;
	}
}
