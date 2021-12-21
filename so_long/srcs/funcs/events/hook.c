/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:25:03 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/21 11:52:03 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	hook(int keycode, t_mlx *mlx)
{
	if (keycode == mlx->keys.escape)
		mlx_close(mlx);
	else if (keycode == mlx->keys.up)
		mlx->player.move += up(mlx);
	else if (keycode == mlx->keys.down)
		mlx->player.move += down(mlx);
	else if (keycode == mlx->keys.left)
		mlx->player.move += left(mlx);
	else if (keycode == mlx->keys.right)
		mlx->player.move += right(mlx);
	print_move(mlx);
	return (0);
}
