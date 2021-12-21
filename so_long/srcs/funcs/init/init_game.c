/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/21 12:34:41 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	check_filename(char *filename)
{
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4))
		error("Nom de map invalide");
}

void	init_game(t_mlx *mlx, char *filename)
{
	check_filename(filename);
	mlx->ptr = mlx_init();
	mlx->define = init_define();
	mlx->keys = init_keys();
	mlx->point = init_point();
	init_map(mlx, filename);
	mlx->empty.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./srcs/img/empty.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./srcs/img/wall.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->player.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./srcs/img/player1.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./srcs/img/exit.xpm", &mlx->map.item_width, &mlx->map.item_height);
	mlx->coin = init_coin(mlx);
	init_window(mlx);
	put_image(mlx);
}
