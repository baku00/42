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

#include "../../../../../so_long.h"

void	put_player(t_mlx *mlx, int y, int x)
{
	t_point	point;

	point.x = x;
	point.y = y;
	mlx->point.point[y][x] = mlx->define.start_player_position;
	mlx->player.point = point;
	mlx->player.move = 0;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->player.img, x * mlx->map.item_width, y * mlx->map.item_height);
}
