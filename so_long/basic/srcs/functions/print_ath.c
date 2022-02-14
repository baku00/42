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

#include "../../so_long.h"

void	print_ath(t_mlx *mlx)
{
	printf("----------------------\n");
	printf("Nombre de movements:\t%d\n", mlx->elements.player.movement);
	printf("Pièce récupéré:\t\t%d\n", \
	mlx->elements.collectible.total_count - mlx->elements.collectible.count);
	printf("Pièce restante:\t\t%d\n", mlx->elements.collectible.count);
}