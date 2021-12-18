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

#include "../../../../../so_long.h"

void	put_image(t_mlx *mlx)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	line = "";
	while (line)
	{
		j = -1;
		while (line[++j])
		{
			if (line[j] == mlx->define.wall)
				put_wall(mlx, i, j);
			else if (line[j] == mlx->define.empty)
				put_empty(mlx, i, j);
			else if (line[j] == mlx->define.exit)
				put_exit(mlx, i, j);
			else if (line[j] == mlx->define.start_player_position)
				put_player(mlx, i, j);
			else if (line[j] == mlx->define.collectible)
				put_coin(mlx, i, j);
		}
		i++;
		line = mlx->map.line.line[i];
	}
}
