/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:00 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/01 01:23:08 by dgloriod         ###   ########.fr       */
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

static void	put_images(t_mlx *mlx)
{
	size_t	x;
	size_t	y;
	void	*img;

	y = -1;
	while (++y < mlx->file.height)
	{
		x = -1;
		while (++x < mlx->file.width - 1)
		{
			img = mlx->elements.empty.img;
			if (mlx->file.point[y][x] == COLLECTIBLE)
				img = mlx->elements.collectible.img;
			else if (mlx->file.point[y][x] == PLAYER)
				img = mlx->elements.player.img;
			else if (mlx->file.point[y][x] == WALL)
				img = mlx->elements.wall.img;
			else if (mlx->file.point[y][x] == IA)
				img = mlx->elements.ia.img;
			register_image(mlx, img, x, y);
		}
	}
}

void	set_images(t_mlx *mlx)
{
	int	width;
	int	height;

	width = ITEM_WIDTH;
	height = ITEM_HEIGHT;
	mlx->elements.collectible.img = \
		mlx_xpm_file_to_image(mlx->ptr, COLLECTIBLE_IMG, &width, &height);
	mlx->elements.exit.img = \
		mlx_xpm_file_to_image(mlx->ptr, EXIT_IMG, &width, &height);
	mlx->elements.empty.img = \
		mlx_xpm_file_to_image(mlx->ptr, EMPTY_IMG, &width, &height);
	mlx->elements.player.img = \
		mlx_xpm_file_to_image(mlx->ptr, PLAYER_IMG, &width, &height);
	mlx->elements.wall.img = \
		mlx_xpm_file_to_image(mlx->ptr, WALL_IMG, &width, &height);
	mlx->elements.ia.img = \
		mlx_xpm_file_to_image(mlx->ptr, IA_IMG, &width, &height);
	mlx->elements.ia.img_2 = \
		mlx_xpm_file_to_image(mlx->ptr, IA_2_IMG, &width, &height);
	ft_putstr_fd("Placement\n", 1);
	put_images(mlx);
}
#endif
