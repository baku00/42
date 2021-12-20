/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

int	mlx_close(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.line.line[i])
		free(mlx->map.line.line[i++]);
	free(mlx->map.line.line);
	i = 0;
	while (mlx->point.point[i])
		free(mlx->point.point[i++]);
	free(mlx->point.point);
	mlx_destroy_window(mlx->ptr, mlx->window.ptr);
	exit(0);
}
