/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:11 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 21:39:47 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	clean_file(t_mlx *mlx)
{
	size_t	y;

	if (mlx->file.line)
		free(mlx->file.line);
	if (mlx->file.content)
		free(mlx->file.content);
	if (mlx->file.name)
		free(mlx->file.name);
	if (mlx->file.point)
	{
		y = -1;
		while (++y < mlx->file.height)
			if (mlx->file.point[y])
				free(mlx->file.point[y]);
		free(mlx->file.point);
	}
}

void	clean_image(t_mlx *mlx)
{
	if (mlx->elements.collectible.img)
		mlx_destroy_image(mlx->ptr, mlx->elements.collectible.img);
	if (mlx->elements.exit.img)
		mlx_destroy_image(mlx->ptr, mlx->elements.exit.img);
	if (mlx->elements.player.img)
		mlx_destroy_image(mlx->ptr, mlx->elements.player.img);
	if (mlx->elements.wall.img)
		mlx_destroy_image(mlx->ptr, mlx->elements.wall.img);
	if (mlx->elements.empty.img)
		mlx_destroy_image(mlx->ptr, mlx->elements.empty.img);
}

// if (mlx->ptr)
// 	mlx_destroy_display(mlx->ptr);
void	clean_mlx(t_mlx *mlx)
{
	if (mlx->window.ptr)
		mlx_destroy_window(mlx->ptr, mlx->window.ptr);
	free(mlx->ptr);
}

#ifndef WITH_BONUS

int	mlx_close(t_mlx *mlx)
{
	printf("Nettoyage du fichier\n");
	clean_file(mlx);
	printf("Fichier nettoye\n");
	if (mlx->ptr)
	{
		printf("Nettoyage des images\n");
		clean_image(mlx);
		printf("Images nettoyees\n");
		printf("Nettoyage de la mlx\n");
		clean_mlx(mlx);
		printf("MLX nettoyee\n");
	}
	exit(0);
	return (0);
}
#endif
