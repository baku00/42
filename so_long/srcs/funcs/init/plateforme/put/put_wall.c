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

void	put_wall(t_mlx *mlx, int y, int x)
{
	mlx->point.point[y][x] = mlx->define.wall;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->wall.img, x * mlx->map.item_width, y * mlx->map.item_height);
}