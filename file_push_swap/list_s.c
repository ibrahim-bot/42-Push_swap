/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:19:03 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/16 22:46:54 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
		nb++;
		tmp = tmp->nxt;
	}
	return (nb);
}
