/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:06:20 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/11 14:21:36 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_front(t_elem **list, int valeur)
{
	t_elem	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->val = valeur;
	new->nxt = *list;
	*list = new;
}

void	add_end(t_elem **list, int valeur)
{
	t_elem *new;
	t_elem *tmp;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(EXIT_FAILURE);
	if (*list == NULL)
	{
		new->val = valeur;
		new->nxt = NULL;
		*list = new;
		return ;
	}
	else
	{
		new->val = valeur;
		new->nxt = NULL;
		tmp = *list;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = new;
	}
}

void	print_list(t_elem *list)
{
	t_elem *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d->", tmp->val);
		tmp = tmp->nxt;
	}
	printf("NULL\n");
}

int		check_list(t_elem *list)
{
	if (list == NULL)
		return (1);
	return (0);
}

void	del_list_front(t_elem **list)
{
	t_elem	*tmp;

	if (list == NULL)
		return ;
	tmp = (*list)->nxt;
	free(*list);
	*list = tmp;
}
