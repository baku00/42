/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:46 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/28 02:40:19 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../basic/so_long.h"
#ifdef WITH_BONUS

static bool	check_char_bonus(t_mlx *mlx, int y, int x)
{
	char	c;

	c = mlx->file.point[y][x];
	if (c == IA)
		mlx->elements.ia.count++;
	return (!check_char(mlx, y, x) && c != IA);
}

bool	valid_char(t_mlx *mlx, int y, int x)
{
	return (!check_char_bonus(mlx, y, x));
}

void	check_limit_bonus(t_mlx *mlx)
{
	if (mlx->elements.ia.count > MAX_IA_LIMIT && \
		MAX_IA_LIMIT != -1)
		ft_exit(mlx, ERROR_TO_MANY_IA, 1);
	else if (mlx->elements.ia.count < MIN_IA_LIMIT)
		ft_exit(mlx, ERROR_NOT_ENOUGH_IA, 1);
	check_limit_basic(mlx);
}

void	check_limit(t_mlx *mlx)
{
	return (check_limit_bonus(mlx));
}
#endif
