/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:11 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/01 01:22:59 by dgloriod         ###   ########.fr       */
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
	ft_putstr_fd("Nettoyage du fichier\n", 1);
	clean_file(mlx);
	ft_putstr_fd("Fichier nettoye\n", 1);
	if (mlx->ptr)
	{
		ft_putstr_fd("Nettoyage des images\n", 1);
		clean_image_bonus(mlx);
		ft_putstr_fd("Images nettoyees\n", 1);
		ft_putstr_fd("Nettoyage de la mlx\n", 1);
		clean_mlx(mlx);
		ft_putstr_fd("MLX nettoyee\n", 1);
	}
	exit(0);
	return (0);
}
#endif
