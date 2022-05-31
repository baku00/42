/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:31 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 18:54:31 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../basic/so_long.h"
#ifdef WITH_BONUS

static void	register_image(t_mlx *mlx, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
			img, x * ITEM_WIDTH, y * ITEM_HEIGHT);
	else
		ft_exit(mlx, "Erreur lors du placement d'une image", 1);
}

static void	animations_bonus(t_mlx *mlx)
{
	size_t	x;
	size_t	y;
	void	*img;

	if (mlx->elements.player.movement % 2)
		img = mlx->elements.ia.img;
	else
		img = mlx->elements.ia.img_2;
	y = -1;
	while (++y < mlx->file.height)
	{
		x = -1;
		while (++x < mlx->file.width - 1)
		{
			if (mlx->file.point[y][x] == IA)
				register_image(mlx, img, x, y);
		}
	}
}

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
	animations_bonus(mlx);
	return (move_bonus(mlx, y, x));
}
#endif
