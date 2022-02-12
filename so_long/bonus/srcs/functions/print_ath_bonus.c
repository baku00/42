/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:44 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:45 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	print_ath(t_mlx *mlx)
{
	char	*movements;
	char	*collectible_collected;
	char	*collectible_remaning;

	movements = ft_itoa(mlx->elements.player.movement);
	collectible_collected = ft_itoa(mlx->elements.collectible.total_count - mlx->elements.collectible.count);
	collectible_remaning = ft_itoa(mlx->elements.collectible.count);
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.wall.img, \
		0 * ITEM_WIDTH, \
		0 * ITEM_HEIGHT);
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.wall.img, \
		1 * ITEM_WIDTH, \
		0 * ITEM_HEIGHT);
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.wall.img, \
		2 * ITEM_WIDTH, \
		0 * ITEM_HEIGHT);
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.wall.img, \
		3 * ITEM_WIDTH, \
		0 * ITEM_HEIGHT);
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
		mlx->elements.wall.img, \
		4 * ITEM_WIDTH, \
		0 * ITEM_HEIGHT);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 3, 10, 0xffffff, "Nombre de mouvements: ");
	mlx_string_put(mlx->ptr, mlx->window.ptr, 140, 10, 0xffffff, movements);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 3, 20, 0xffffff, "Piece recupere: ");
	mlx_string_put(mlx->ptr, mlx->window.ptr, 140, 20, 0xffffff, collectible_collected);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 3, 30, 0xffffff, "Piece restante: ");
	mlx_string_put(mlx->ptr, mlx->window.ptr, 140, 30, 0xffffff, collectible_remaning);
	printf("----------------------\n");
	printf("Nombre de movements:\t%s\n", movements);
	printf("Pièce récupéré:\t\t%s\n", collectible_collected);
	printf("Pièce restante:\t\t%s\n", collectible_remaning);
	free(movements);
	free(collectible_collected);
	free(collectible_remaning);
}
