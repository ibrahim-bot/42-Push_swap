/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:35:54 by ibrahim           #+#    #+#             */
/*   Updated: 2021/03/04 18:13:48 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list  *init()
{
    t_list  *list;
    t_elem  *elem;

    list = malloc(sizeof(*list));
    elem = malloc(sizeof(*elem));
    if (list == NULL || elem == NULL)
        exit(EXIT_FAILURE);
    elem->nb = 0;
    elem->next = NULL;
    list->first = elem;
    return (list);
}

void    add_front_list(t_list *list, int newnb)
{
    t_elem *new;

    new = malloc(sizeof(*new));
    if (new == NULL)
        exit(EXIT_FAILURE);
    new->nb = newnb;
    new->next = list->first;
    list->first = new;
}

void    del_elem_list(t_list *list)
{
    t_elem *elem;

    if (list == NULL)
        exit(EXIT_FAILURE);
    if (list->first != NULL)
    {
        elem = list->first;
        list->first = list->first->next;
        free(elem);
    }
}

void    print_list(t_list *list)
{
    t_elem *elem;

    if (list == NULL)
        exit(EXIT_FAILURE);
    elem = list->first;
    while (elem)
    {
        printf("%d -> ", elem->nb);
        elem = elem->next;
    }
    printf("NULL\n");
}

int main()
{
    t_list *list;

    list = init();

    add_front_list(list, 4);
    add_front_list(list, 8);
    add_front_list(list, 15);
    del_elem_list(list);

    print_list(list);
    return (0);
}