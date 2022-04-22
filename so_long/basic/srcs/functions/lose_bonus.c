/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:20 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/22 03:57:26 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#ifdef WITH_BONUS

void	lose(t_mlx *mlx)
{
	printf("Perdu !\n");
	mlx_close(mlx);
}
#endif
