/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:25:03 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:25:20 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	count_char(const char *str, const char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i]) {
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
