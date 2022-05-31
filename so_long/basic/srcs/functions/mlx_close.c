/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:11 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 19:24:48 by dgloriod         ###   ########.fr       */
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
	ft_putstr_fd("Nettoyage du fichier\n", 1);
	clean_file(mlx);
	ft_putstr_fd("Fichier nettoye\n", 1);
	if (mlx->ptr)
	{
		ft_putstr_fd("Nettoyage des images\n", 1);
		clean_image(mlx);
		ft_putstr_fd("Images nettoyees\n", 1);
		ft_putstr_fd("Nettoyage de la mlx\n", 1);
		clean_mlx(mlx);
		ft_putstr_fd("MLX nettoyee\n", 1);
	}
	exit(0);
	return (0);
}
#endif
