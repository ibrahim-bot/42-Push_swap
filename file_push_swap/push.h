/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:04:01 by ibrahim           #+#    #+#             */
/*   Updated: 2021/03/05 15:19:27 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_elem
{
    int val;
    struct s_elem *nxt;
}t_elem;

void        ft_putstr(char *str);
int         ft_isdigit(int c);
long long   ft_atoi(const char *str);
char        **ft_split(char *str, char *charset);
int         ft_error(char *str);
int         check_num(char **av);
int         check_doublon(char **av);
int         check_len(char **av);
int			check_error(char **av);
t_elem      *add_front(t_elem *list, int valeur);
t_elem      *add_end(t_elem *list, int valeur);
void        print_list(t_elem *list);
int         check_list(t_elem *list);
t_elem      *del_list_front(t_elem *list);
t_elem      *del_list_end(t_elem *list);
t_elem      *delet_list(t_elem *list);

#endif