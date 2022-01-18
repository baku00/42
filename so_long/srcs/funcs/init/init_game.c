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

#include "../../../so_long.h"

void	init_game(t_mlx *mlx, char *filename)
{
	mlx->ptr = mlx_init();
	mlx->define = init_define();
	mlx->keys = init_keys();
	mlx->point = init_point();
	verify_map_filename(mlx, filename);
	init_map(mlx, filename);
	mlx->empty.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./config/img/empty.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./config/img/wall.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->player.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./config/img/player1.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./config/img/exit.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->coin = init_coin(mlx);
	init_window(mlx);
	put_image(mlx);
}
