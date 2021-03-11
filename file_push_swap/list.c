/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:06:20 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/05 13:18:25 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem *add_front(t_elem *list, int valeur)
{
    t_elem *new; 

    new = malloc(sizeof(*new));
    if (new == NULL)
        exit(EXIT_FAILURE);
    new->val = valeur;
    new->nxt = list;
    return (new);
}

t_elem *add_end(t_elem *list, int valeur)
{
    t_elem *new;
    t_elem *tmp;

    new = malloc(sizeof(*new));
    if (new == NULL)
        exit(EXIT_FAILURE);
    new->val = valeur;
    new->nxt = NULL;
    if(list == NULL)
        return (new);
    else
    {
        tmp = list;
        while(tmp->nxt != NULL)
            tmp = tmp->nxt;
        tmp->nxt = new;
        return (list);
    }
}

void    print_list(t_elem *list)
{
    t_elem *tmp;

    tmp = list;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->val);
        tmp = tmp->nxt;
    }
}

int     check_list(t_elem *list)
{
    if (list == NULL)
        return (1);
    return (0);
}

t_elem  *del_list_front(t_elem *list)
{
    t_elem  *tmp;

    if (list == NULL)
        return (NULL);
    tmp = list->nxt;
    free(list);
    return (tmp);
}
