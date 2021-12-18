/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_contains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

t_contains	init_contains(t_mlx *mlx)
{
	t_contains	contains;

	contains.coin = 0;
	contains.player = 0;
	contains.wall = 0;
	contains.exit = 0;
	contains.empty = 0;
	return (contains);
}
