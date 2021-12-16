/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:27:28 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:32:56 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	hook(int keycode, t_mlx *mlx)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == ESCAPE)
		mlx_close(mlx);
	if (keycode == UP)
		mlx->player->move += up(mlx);
	else if (keycode == DOWN)
		mlx->player->move += down(mlx);
	else if (keycode == LEFT)
		mlx->player->move += left(mlx);
	else if (keycode == RIGHT)
		mlx->player->move += right(mlx);
	print_move(mlx);
	return (0);
}
