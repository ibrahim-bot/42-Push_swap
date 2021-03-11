/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:19:03 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/11 16:48:49 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del_list_end(t_elem **list)
{
	t_elem	*tmp;
	t_elem	*ptmp;

	if (*list == NULL)
		return ;
	if ((*list)->nxt == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	ptmp = *list;
	while (tmp->nxt != NULL)
	{
		ptmp = tmp;
		tmp = tmp->nxt;
	}
	ptmp->nxt = NULL;
	free(tmp);
}

void	delet_list(t_elem **list)
{
	t_elem	*tmp;

	if (list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->nxt;
		free(*list);
		*list = tmp;
	}
}

void	fill_list(t_elem **list, char **av)
{
	int i;

	i = 0;
	if (ft_isdigit(av[0][0]) == 0 && av[0][0] != '-')
		i++;
	while (av[i])
	{
		add_end(list, ft_atoi(av[i]));
		i++;
	}
}

int		len_list(t_elem *list)
{
	int		nb;
	t_elem	*tmp;

	nb = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->nxt;
		nb++;
	}
	return (nb);
}
