/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:44 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 19:26:21 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_ath_basic(t_mlx *mlx)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("----------------------\n");
	ft_putstr_fd("Nombre de movements:\t", 1);
	ft_putnbr_fd(mlx->elements.player.movement);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Pièce récupéré:\t\t", 1);
	ft_putnbr_fd(mlx->elements.collectible.total_count \
		- mlx->elements.collectible.count, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Pièce restante:\t\t", 1);
	ft_putnbr_fd(mlx->elements.collectible.count, 1);
	ft_putstr_fd("\n", 1);
}

#ifndef WITH_BONUS

void	print_ath(t_mlx *mlx)
{
	print_ath_basic(mlx);
}
#endif
