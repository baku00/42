/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkDoor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:48:41 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:49:02 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../so_long.h"

int	check_door(t_mlx *mlx)
{
	return (mlx->player->point.x == mlx->exit->point.x && \
			mlx->player->point.y == mlx->exit->point.y);
}
