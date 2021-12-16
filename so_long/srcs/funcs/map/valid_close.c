/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:54:30 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:59:04 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	valid_close(char *filename)
{
	t_map	map;

	map.fd = open(filename, O_RDONLY);
	map.line = "";
	map.height = 0;
	map.first = 1;
	while (map.line)
	{
		map.line = get_next_line(map.fd);
		if (map.line)
			map.length = ft_strlen(map.line);
		else
			break ;
		map.height++;
		if (first)
		{
			first = 0;
			map.width = map.length;
		}
		else if (map.width != map.length)
			error();
	}
	if (map.width == map.height)
		error();
	return (1);
}
