/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:31 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:32 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	set_animation(t_mlx *mlx, int y, int x, int i)
{
	void	*img;

	img = mlx->elements.ia.img;
	if (i % 2)
		img = mlx->elements.ia.img_2;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		img, \
		x * ITEM_WIDTH, \
		y * ITEM_HEIGHT);
}

void	change_animations(t_mlx *mlx)
{
	static unsigned int	i;
	size_t				x;
	size_t				y;

	y = 0;
	while (y < mlx->file.height)
	{
		x = 0;
		while (x < mlx->file.width - 1)
		{
			if (mlx->file.point[y][x] == IA)
				set_animation(mlx, y, x, i);
			x++;
		}
		y++;
	}
	i++;
	if (i > 4000000000)
		i = 0;
}
