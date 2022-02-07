/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:11 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:13 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	mlx_close(t_mlx *mlx)
{
	size_t	y;

	free(mlx->file.content);
	y = -1;
	while (++y < mlx->file.height)
		free(mlx->file.point[y]);
	free(mlx->file.point);
	exit(0);
	return (0);
}
