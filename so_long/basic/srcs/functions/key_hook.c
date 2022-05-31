/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:56 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/01 01:20:33 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	int	move;

	move = 0;
	if (keycode == ESCAPE)
		mlx_close(mlx);
	else if (keycode == UP)
		move = can_move(mlx, -1, 0);
	else if (keycode == DOWN)
		move = can_move(mlx, 1, 0);
	else if (keycode == LEFT)
		move = can_move(mlx, 0, -1);
	else if (keycode == RIGHT)
		move = can_move(mlx, 0, 1);
	if (move)
	{
		mlx->elements.player.movement += move;
		apply_move(mlx);
	}
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		print_ath(mlx);
	return (0);
}
