/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:46:50 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:48:29 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../so_long.h"

char	*check_coin(t_mlx *mlx, int x, int y)
{
	char	*point;
	char	*result;

	point = ft_calloc(1, sizeof(char));
	point = get_point(point, x, y);
	result = ft_strnstr(mlx->coin->point.point, point, \
			ft_strlen(mlx->coin->point.point));
	if (ft_strnstr(mlx->coin->coin_taked.point, point, \
				ft_strlen(mlx->coin->coin_taked.point)))
		return (NULL);
	else
		mlx->coin->coin_taked.point = \
			ft_strjoin(mlx->coin->coin_taked.point, point);
	free(point);
	return (result);
}
