/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:40:57 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/01 16:14:39 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

int	find_next(char *arg, int i, char c)
{
	while (arg[++i] && arg[i] != c)
		;
	if (!arg[i])
		i = -1;
	return (i);
}

int	find_next_chars(char *arg, int i, char c1, char c2)
{
	while (arg[++i] && arg[i] != c1 && arg[i] != c2)
		;
	if (!arg[i])
		i = 0;
	if (arg[i] == c2)
		i *= -1;
	return (i);
}