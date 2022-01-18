/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

static void	set_accepted_chars(t_map *map, t_mlx *mlx)
{
	map->accepted_chars[0] = mlx->define.empty;
	map->accepted_chars[1] = mlx->define.wall;
	map->accepted_chars[2] = mlx->define.collectible;
	map->accepted_chars[3] = mlx->define.exit;
	map->accepted_chars[4] = mlx->define.start_player_position;
	map->accepted_chars[5] = '\0';
}

static void	set_item(t_map *map)
{
	map->wall = 0;
	map->empty = 0;
	map->player = 0;
	map->coin = 0;
	map->exit = 0;
}

void	init_map(t_mlx *mlx, char *filename)
{
	t_map	map;
	int		i;

	map.fd = open(filename, O_RDONLY);
	map.width = 0;
	map.height = 0;
	map.char_to_string[1] = '\0';
	set_accepted_chars(&map, mlx);
	map.item_width = 40;
	map.item_height = 40;
	map.line_counter = 0;
	set_item(&map);
	mlx->map = map;
	mlx->map.contains = init_contains();
	mlx->map.line = get_line(mlx);
	verify_map(mlx);
	mlx->point.point = ft_calloc(mlx->map.height + 1, sizeof(int *));
	i = 0;
	while (i < mlx->map.height + 1)
		mlx->point.point[i++] = ft_calloc(mlx->map.width + 1, sizeof(int));
}
