/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:50:33 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/20 23:15:22 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*getcmd(char *arg)
{
	int	i;

	i = -1;
	if (!arg)
		return (ft_strdup(""));
	while (arg[++i] && arg[i] != SPACE)
		;
	return ft_substr(arg, 0, i);
}