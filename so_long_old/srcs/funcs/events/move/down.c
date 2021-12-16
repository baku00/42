/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:38:52 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:41:09 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

int	down(t_mlx *mlx)
{
	int	item_margin_height;

	item_margin_height = mlx->map->item_margin_height;
	if (mlx->player->point.y + 40 >= mlx->height - item_margin_height || \
			check_wall(mlx, mlx->player->point.x, mlx->player->point.y + 40))
		return (0);
	if (check_coin(mlx, mlx->player->point.x, mlx->player->point.y + 40))
		remove_coin(mlx);
	if (!mlx->coin->count)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->exit->img, mlx->exit->point.x, mlx->exit->point.y);
		mlx->exit->is_enable = 1;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->empty, mlx->player->point.x, mlx->player->point.y);
	mlx->player->point.y += 40;
	if (mlx->exit->is_enable && check_door(mlx))
		win();
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->player->img, mlx->player->point.x, mlx->player->point.y);
	return (1);
}
