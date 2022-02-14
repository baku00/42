/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:31 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:32 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	apply_move(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.empty.img, \
		mlx->elements.player.x * ITEM_WIDTH, \
		mlx->elements.player.y * ITEM_HEIGHT);
	if (!(mlx->elements.exit.x == mlx->elements.player.x && \
		mlx->elements.exit.y == mlx->elements.player.y))
		mlx->file.point[mlx->elements.player.y][mlx->elements.player.x] = EMPTY;
	mlx->elements.player.x = mlx->elements.player.current_x;
	mlx->elements.player.y = mlx->elements.player.current_y;
	if (!(mlx->elements.exit.x == mlx->elements.player.x && \
		mlx->elements.exit.y == mlx->elements.player.y))
		mlx->file.point[mlx->elements.player.y] \
		[mlx->elements.player.x] = PLAYER;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.player.img, mlx->elements.player.x * ITEM_WIDTH, \
		mlx->elements.player.y * ITEM_HEIGHT);
}

int	move(t_mlx *mlx, int y, int x)
{
	char	c;
	int		can_move;

	mlx->elements.player.current_y = mlx->elements.player.y + y;
	mlx->elements.player.current_x = mlx->elements.player.x + x;
	c = mlx->file.point[mlx->elements.player.current_y] \
		[mlx->elements.player.current_x];
	if (c == COLLECTIBLE)
		get_collectible(mlx, mlx->elements.player.current_y, \
			mlx->elements.player.current_x);
	else if (c == EXIT && mlx->elements.exit.is_enabled)
		win(mlx);
	can_move = (c == COLLECTIBLE || c == EXIT || c == EMPTY);
	if (can_move)
		apply_move(mlx);
	return (can_move);
}
