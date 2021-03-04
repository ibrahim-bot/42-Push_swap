/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:04:01 by ibrahim           #+#    #+#             */
/*   Updated: 2021/03/04 16:04:04 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

void        ft_putstr(char *str);
int         ft_isdigit(int c);
long long   ft_atoi(const char *str);
int         ft_error(char *str);
int         check_num(char **av);
int         check_doublon(char **av);
int         check_len(char **av);
int			check_error(int ac, char **av);

#endif