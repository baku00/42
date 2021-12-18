/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

void	init_window(t_mlx *mlx)
{
	t_window	window;

	window.width = mlx->map.width * mlx->map.item_width;
	window.height = mlx->map.height * mlx->map.item_height;
	window.title = "So Long";
	window.ptr = \
	mlx_new_window(mlx->ptr, window.width, window.height, window.title);
	mlx->window = window;
}
