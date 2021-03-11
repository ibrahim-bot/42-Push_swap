/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:19:03 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/05 13:18:19 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem  *del_list_end(t_elem *list)
{
    t_elem *tmp;
    t_elem *ptmp;

    if (list == NULL)
        return (NULL);
    if (list->nxt == NULL)
    {
        free(list);
        return (NULL);
    }
    tmp = list;
    ptmp = list;
    while (tmp->nxt != NULL)
    {
        ptmp = tmp;
        tmp = tmp->nxt;
    }
    ptmp->nxt = NULL;
    free(tmp);
    return (list);
}

t_elem  *delet_list(t_elem *list)
{
    t_elem  *tmp;

    if(list == NULL)
        return (NULL);
    else
    {
        tmp = list->nxt;
        free(list);
        return (delet_list(tmp));
    }
}

// int main(int ac, char **av)
// {
//     t_elem *list = NULL;
//     int i;

//     i = 1;
//     while (av[i])
//     {
//         list = add_end(list, ft_atoi(av[i]));
//         i++;
//     }
//     print_list(list);
   
//     list = del_list_front(list);
//     printf("\n");
//     print_list(list);
   
//     list = del_list_end(list);
//     printf("\n");
//     print_list(list);

//     list = delet_list(list);
//     printf("salut\n");
//     print_list(list);
//     return 0;
// }