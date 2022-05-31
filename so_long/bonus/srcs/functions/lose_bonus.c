/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:20 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/01 01:22:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../basic/so_long.h"
#ifdef WITH_BONUS

void	lose(t_mlx *mlx)
{
	ft_putstr_fd("Perdu !\n", 1);
	mlx_close(mlx);
}
#endif
