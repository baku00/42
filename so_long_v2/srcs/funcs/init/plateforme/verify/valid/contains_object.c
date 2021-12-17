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

#include "../../../../../../so_long.h"

void	contains_object(char *line, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (line[i]) {
		if (line[i] == mlx->define.wall)
			mlx->map.contains.wall++;
		else if (line[i] == mlx->define.empty)
			mlx->map.contains.empty++;
		else if (line[i] == mlx->define.exit)
			mlx->map.contains.exit++;
		else if (line[i] == mlx->define.start_player_position)
			mlx->map.contains.player++;
		else if (line[i] == mlx->define.collectible)
			mlx->map.contains.coin++;
		i++;
	}
}
