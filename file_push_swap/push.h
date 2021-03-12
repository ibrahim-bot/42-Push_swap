/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:04:01 by ibrahim           #+#    #+#             */
/*   Updated: 2021/03/12 10:59:18 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_elem
{
	int				val;
	struct s_elem	*nxt;
}				t_elem;

typedef struct	s_check
{
	char	**arg;
	char	*str;
	int		cas;
}				t_check;

int				parsing(char *buffer);
int				get_next_line(int fd, char **line);
size_t			ft_l(char const *str);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_sub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
void			ft_putstr(char *str);
int				ft_isdigit(int c);
int				ft_strcmp(char *s1, char *s2);
long long		ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
int				ft_error(char *str);
int				ft_error(char *str);
int				check_num(char **av, int cas);
int				check_doublon(char **av);
int				check_len(char **av);
int				check_error(int ac, char **av, t_check *check);
void			add_front(t_elem **list, int valeur);
void			add_end(t_elem **list, int valeur);
void			print_list(t_elem *list);
int				check_list(t_elem *list);
void			del_list_front(t_elem **list);
void			delet_list(t_elem **list);
void			del_list_end(t_elem **list);
int				len_list(t_elem *list);
void			fill_list(t_elem **list, char **av);
char			*ft_strncpy(char *dest, char *src, int n);
int				verif_error(t_check *check, char **av);
void			tri_list(t_elem **list_a, t_elem **list_b, t_check *check);
void			exec_sa_sb(t_elem **list);
void			exec_ss(t_elem **list_a, t_elem **list_b);
void			exec_pa(t_elem **list_a, t_elem **list_b);
void			exec_pb(t_elem **list_a, t_elem **list_b);
void			exec_ra_rb(t_elem **list_a);
void			exec_rr(t_elem **list_a, t_elem **list_b);
void			exec_rra_rrb(t_elem **list_a);
void			exec_rrr(t_elem **list_a, t_elem **list_b);

#endif