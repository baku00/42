/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

int	move(t_mlx *mlx)
{
	if (check_wall(mlx, mlx->point.point, \
		mlx->player.point.current_x, mlx->player.point.current_y))
		return (0);
	if (check_coin(mlx, mlx->point.point, \
		mlx->player.point.current_x, mlx->player.point.current_y))
		remove_coin(mlx, mlx->player.point.current_x, \
			mlx->player.point.current_y);
	if (!mlx->coin.count && !mlx->exit.is_enable)
		enable_door(mlx, mlx->exit.point.x, mlx->exit.point.y);
	if (mlx->exit.is_enable && check_door(mlx, mlx->point.point, \
		mlx->player.point.current_x, mlx->player.point.current_y))
		win(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, mlx->empty.img, \
		mlx->player.point.x * mlx->map.item_width, \
		mlx->player.point.y * mlx->map.item_height);
	mlx->player.point.y = mlx->player.point.current_y;
	mlx->player.point.x = mlx->player.point.current_x;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, mlx->player.img, \
		mlx->player.point.x * mlx->map.item_width, \
		mlx->player.point.y * mlx->map.item_height);
	return (1);
}
