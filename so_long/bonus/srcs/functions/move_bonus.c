/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:31 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/28 02:53:46 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../basic/so_long.h"
#ifdef WITH_BONUS

static int	move_bonus(t_mlx *mlx, int y, int x)
{
	char	c;

	mlx->elements.player.current_y = mlx->elements.player.y + y;
	mlx->elements.player.current_x = mlx->elements.player.x + x;
	c = mlx->file.point[mlx->elements.player.current_y] \
		[mlx->elements.player.current_x];
	if (c == IA)
		lose(mlx);
	return (move(mlx, y, x) && c != IA);
}

int	can_move(t_mlx *mlx, int y, int x)
{
	return (move_bonus(mlx, y, x));
}
#endif
