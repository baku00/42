/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/21 11:50:52 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

int	mlx_close(t_mlx *mlx)
{
	free(mlx->map.line.line);
	free(mlx->point.point);
	mlx_destroy_window(mlx->ptr, mlx->window.ptr);
	exit(0);
}
