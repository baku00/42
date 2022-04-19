/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collectible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:41 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	get_collectible(t_mlx *mlx, int y, int x)
{
	mlx->elements.collectible.count -= 1;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.empty.img, x * ITEM_WIDTH, y * ITEM_HEIGHT);
	if (!mlx->elements.collectible.count)
	{
		mlx->elements.exit.is_enabled = 1;
		mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
			mlx->elements.exit.img, \
			mlx->elements.exit.x * ITEM_WIDTH, \
			mlx->elements.exit.y * ITEM_HEIGHT);
	}
}
