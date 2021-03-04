/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:43:13 by ichougra          #+#    #+#             */
/*   Updated: 2021/03/04 16:21:08 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(char **av)
{
	
}

int main(int ac, char **av)
{
	if (check_error(ac, av) == 1)
		return (1);
	checker(av);
	return (0);
}