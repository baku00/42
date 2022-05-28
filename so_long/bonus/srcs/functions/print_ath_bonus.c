/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ath_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:44 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/28 02:56:01 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../basic/so_long.h"
#ifdef WITH_BONUS

static void	print_ath_bonus(t_mlx *mlx, char *movement, \
	char *collected, char *remaning)
{
	mlx_string_put(mlx->ptr, mlx->window.ptr, 3, 10, 0xffffff, \
		"Nombre de mouvements: ");
	mlx_string_put(mlx->ptr, mlx->window.ptr, 140, 10, 0xffffff, movement);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 3, 20, 0xffffff, \
		"Piece recupere: ");
	mlx_string_put(mlx->ptr, mlx->window.ptr, 140, 20, 0xffffff, collected);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 3, 30, 0xffffff, \
		"Piece restante: ");
	mlx_string_put(mlx->ptr, mlx->window.ptr, 140, 30, 0xffffff, remaning);
	print_ath_basic(mlx);
}

void	print_ath(t_mlx *mlx)
{
	char	*movements;
	char	*collectible_collected;
	char	*collectible_remaning;
	int		i;

	movements = ft_itoa(mlx->elements.player.movement);
	collectible_collected = \
		ft_itoa(mlx->elements.collectible.total_count \
			- mlx->elements.collectible.count);
	collectible_remaning = ft_itoa(mlx->elements.collectible.count);
	i = -1;
	while (++i < 5)
		mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, \
			mlx->elements.wall.img, \
			i * ITEM_WIDTH, \
			0 * ITEM_HEIGHT);
	print_ath_bonus(mlx, movements, collectible_collected, \
		collectible_remaning);
	free(movements);
	free(collectible_collected);
	free(collectible_remaning);
}
#endif
