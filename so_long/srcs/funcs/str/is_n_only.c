/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_n_only.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:25:29 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:26:26 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_n_only(const char *str, const char *search, const int length)
{
	int	i;

	i = 0;
	while (str[i] && i < length)
	{
		if (!ft_strchr(search, str[i]))
			return (0);
		i++;
	}
	return (1);
}
