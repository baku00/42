/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

t_coin	init_coin(t_mlx *mlx)
{
	t_coin	coin;

	coin.count = 0;
	coin.img = mlx_xpm_file_to_image(mlx->ptr, \
		"./srcs/img/coin.xpm", &mlx->map.item_width, &mlx->map.item_height);
	return (coin);
}
