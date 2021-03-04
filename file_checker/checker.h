/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:53:34 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/04 18:24:53 by ibrahim          ###   ########.fr       */
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
    int nb;
    struct s_elem *next;
}t_elem;

typedef struct s_list
{
    t_elem *first;
}t_list;


void        ft_putstr(char *str);
int         ft_isdigit(int c);
long long   ft_atoi(const char *str);
int         ft_error(char *str);
int         check_num(char **av);
int         check_doublon(char **av);
int         check_len(char **av);
int			check_error(int ac, char **av);

#endif