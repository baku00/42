/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:59:19 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 05:02:44 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	valid_shape(char *filename, t_map *map)
{
	int	length;

	map->fd = open(filename, O_RDONLY);
	map->line = "";
	map->width = 0;
	map->height = 0;
	map.first = 1;
	while (map->line)
	{
		map->line = get_next_line(map->fd);
		if (map->line)
			length = ft_strlen(map->line);
		else
			break ;
		map->height++;
		if (map.first)
		{
			map->char_to_string[0] = map->accepted_chars[1];
			if (!is_n_only(map->line, map->char_to_string, length - 1))
				error();
			map.first = 0;
			map->width = length;
		}
		else if (map->width != length || !is_at(map->line, \
				map->char_to_string[0], 0) || \
				!is_at(map->line, map->char_to_string[0], length - 2) || \
				!is_n_only(map->line, map->accepted_chars, length - 1))
			error();
		map->previous_line = map->line;
	}
	if (map->width == map->height || \
			!is_n_only(map->previous_line, \
				map->char_to_string, length - 1))
		error();
	close(map->fd);
	map->fd = open(filename, O_RDONLY);
	return (1);
}
