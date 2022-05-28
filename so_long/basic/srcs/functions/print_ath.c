/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:44 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/28 02:52:04 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_ath_basic(t_mlx *mlx)
{
	printf("\e[1;1H\e[2J");
	printf("----------------------\n");
	printf("Nombre de movements:\t%d\n", mlx->elements.player.movement);
	printf("Pièce récupéré:\t\t%d\n", \
	mlx->elements.collectible.total_count - mlx->elements.collectible.count);
	printf("Pièce restante:\t\t%d\n", mlx->elements.collectible.count);
}

#ifndef WITH_BONUS

void	print_ath(t_mlx *mlx)
{
	print_ath_basic(mlx);
}
#endif
