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

static void check_error(t_mlx *mlx)
{
	if ((mlx->map.contains.wall > MAX_WALL_COUNT && MAX_WALL_COUNT > -1) || mlx->map.contains.wall < MIN_WALL_COUNT)
		error(mlx->error_message.wrong_wall_number);
	if ((mlx->map.contains.empty > MAX_EMPTY_COUNT && MAX_EMPTY_COUNT > -1) || mlx->map.contains.empty < MIN_EMPTY_COUNT)
		error(mlx->error_message.wrong_empty_number);
	if ((mlx->map.contains.exit > MAX_EXIT_COUNT && MAX_EXIT_COUNT > -1) || mlx->map.contains.exit < MIN_EXIT_COUNT)
		error(mlx->error_message.wrong_exit_number);
	if ((mlx->map.contains.player > MAX_PLAYER_COUNT && MAX_PLAYER_COUNT > -1) || mlx->map.contains.player < MIN_PLAYER_COUNT)
		error(mlx->error_message.wrong_player_number);
	if ((mlx->map.contains.coin > MAX_COIN_COUNT && MAX_COIN_COUNT > -1) || mlx->map.contains.coin < MIN_COIN_COUNT)
		error(mlx->error_message.wrong_coin_number);
}

void	contains_object(char *line, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (line[i])
	{
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
	check_error(mlx);
}
