/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:46 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/28 02:53:31 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

#ifndef WITH_BONUS

bool	valid_char(t_mlx *mlx, int y, int x)
{
	return (check_char(mlx, y, x));
}

void	check_limit(t_mlx *mlx)
{
	return (check_limit_basic(mlx));
}

#endif

bool	check_char(t_mlx *mlx, int y, int x)
{
	char	c;

	c = mlx->file.point[y][x];
	if (c == COLLECTIBLE)
	{
		mlx->elements.collectible.count++;
		mlx->elements.collectible.total_count++;
	}
	else if (c == EXIT)
	{
		mlx->elements.exit.x = x;
		mlx->elements.exit.y = y;
		mlx->elements.exit.count++;
	}
	else if (c == WALL)
		mlx->elements.wall.count++;
	else if (c == PLAYER)
	{
		mlx->elements.player.x = x;
		mlx->elements.player.y = y;
		mlx->elements.player.count++;
	}
	return (!(c != EMPTY && c != WALL && c != EXIT \
		&& c != PLAYER && c != COLLECTIBLE));
}

void	check_limit_basic(t_mlx *mlx)
{
	if (mlx->elements.wall.count > MAX_WALL_LIMIT && \
		MAX_WALL_LIMIT != -1)
		ft_exit(mlx, ERROR_TO_MANY_WALL, 1);
	else if (mlx->elements.wall.count < MIN_WALL_LIMIT)
		ft_exit(mlx, ERROR_NOT_ENOUGH_WALL, 1);
	else if (mlx->elements.player.count > MAX_PLAYER_LIMIT && \
		MAX_PLAYER_LIMIT != -1)
		ft_exit(mlx, ERROR_TO_MANY_PLAYER, 1);
	else if (mlx->elements.player.count < MIN_PLAYER_LIMIT)
		ft_exit(mlx, ERROR_NOT_ENOUGH_PLAYER, 1);
	else if (mlx->elements.collectible.count > MAX_COLLECTIBLE_LIMIT && \
		MAX_COLLECTIBLE_LIMIT != -1)
		ft_exit(mlx, ERROR_TO_MANY_COLLECTIBLE, 1);
	else if (mlx->elements.collectible.count < MIN_COLLECTIBLE_LIMIT)
		ft_exit(mlx, ERROR_NOT_ENOUGH_COLLECTIBLE, 1);
	else if (mlx->elements.exit.count > MAX_EXIT_LIMIT && \
		MAX_EXIT_LIMIT != -1)
		ft_exit(mlx, ERROR_TO_MANY_EXIT, 1);
	else if (mlx->elements.exit.count < MIN_EXIT_LIMIT)
		ft_exit(mlx, ERROR_NOT_ENOUGH_EXIT, 1);
}
