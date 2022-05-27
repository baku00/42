/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:11 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 21:20:28 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../basic/so_long.h"
#ifdef WITH_BONUS

static void	clean_image_bonus(t_mlx *mlx)
{
	if (mlx->elements.ia.img)
		mlx_destroy_image(mlx->ptr, mlx->elements.ia.img);
	if (mlx->elements.ia.img_2)
		mlx_destroy_image(mlx->ptr, mlx->elements.ia.img_2);
	clean_image(mlx);
}

int	mlx_close(t_mlx *mlx)
{
	printf("Nettoyage du fichier\n");
	clean_file(mlx);
	printf("Fichier nettoye\n");
	if (mlx->ptr)
	{
		printf("Nettoyage des images\n");
		clean_image_bonus(mlx);
		printf("Images nettoyees\n");
		printf("Nettoyage de la mlx\n");
		clean_mlx(mlx);
		printf("MLX nettoyee\n");
	}
	exit(0);
	return (0);
}
#endif
