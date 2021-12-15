/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkWall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:50:06 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:50:47 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../so_long.h"

char	*check_wall(t_mlx *mlx, int x, int y)
{
	char	*point;
	char	*result;

	point = ft_calloc(1, sizeof(char));
	point = get_point(point, x, y);
	result = ft_strnstr(mlx->wall->point.point, point, \
			ft_strlen(mlx->wall->point.point));
	free(point);
	return (result);
}
