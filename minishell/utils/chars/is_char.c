/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:39:12 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/01 15:50:07 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

int	is_char(char c, char *cs)
{
	int	i;

	i = -1;
	if (!cs)
		return (0);
	while (cs[++i])
		if (c == cs[i])
			return (1);
	return (0);
}

int	find_next_chars(char *arg, int i, char c, char c2)
{
	while (arg[++i] && arg[i] != c && arg[i] != c2)
		;
	if (!arg[i])
		i = 0;
	if (arg[i] == c2)
		i *= -1;
	return (i);
}