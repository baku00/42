/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:41:35 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:43:16 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

int	up(t_mlx *mlx)
{
	int	item_margin_width;

	item_margin_width = mlx->map->item_margin_width;
	if (mlx->player->point.y - 40 < 0 + item_margin_width || \
		checkWall(mlx, mlx->player->point.x, mlx->player->point.y - 40))
		return (0);
	if (checkCoin(mlx, mlx->player->point.x, mlx->player->point.y - 40))
		removeCoin(mlx);
	if (!mlx->coin->count)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->exit->img, mlx->exit->point.x, mlx->exit->point.y);
		mlx->exit->is_enable = 1;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->empty, mlx->player->point.x, mlx->player->point.y);
	mlx->player->point.y -= 40;
	if (mlx->exit->is_enable && checkDoor(mlx))
		win();
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->player->img, mlx->player->point.x, mlx->player->point.y);
	return (1);
}
