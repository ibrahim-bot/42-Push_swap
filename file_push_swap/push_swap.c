/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:47 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/11 17:02:08 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*fill_list(t_elem *list, char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		list = add_end(list, ft_atoi(av[i]));
		i++;
	}
	return (list);
}

int main(int ac, char **av)
{
    t_elem	*list_a;
	t_elem	*list_b;

	(void)ac;
	list_b = NULL;
	list_a = NULL;
    if (check_error(av) == 1)
        return (1);
    list_a = fill_list(list_a, av);
	ft_putstr("sa\n");
    return (0);
}