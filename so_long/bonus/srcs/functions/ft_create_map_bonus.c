/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:06 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:07 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_create_map(t_mlx *mlx)
{
	t_window	window;

	mlx->ptr = mlx_init();
	window.width = \
		((int) (mlx->file.width - 1)) * ITEM_WIDTH;
	window.height = \
		((int) (mlx->file.height)) * ITEM_HEIGHT;
	window.title = "So Long";
	window.ptr = \
	mlx_new_window(mlx->ptr, window.width, window.height, window.title);
	mlx->window = window;
}
