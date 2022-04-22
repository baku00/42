/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:46 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/22 03:50:06 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"
#ifdef WITH_BONUS

static void	check_next_char(t_mlx *mlx, int y, int x)
{
	char	c;

	c = mlx->file.point[y][x];
	if (c == '1')
		mlx->elements.wall.count++;
	else if (c == 'I')
		mlx->elements.ia.count++;
	else if (c == 'P')
	{
		mlx->elements.player.x = x;
		mlx->elements.player.y = y;
		mlx->elements.player.count++;
	}
	else if (c != '0' && c != '1' && c != 'E' && \
		c != 'P' && c != 'C' && c != 'I')
		ft_exit(mlx, ERROR_BAD_CHAR, 1);
}

static void	send_error(t_mlx *mlx)
{
	if (mlx->elements.collectible.count > MAX_COLLECTIBLE_LIMIT && \
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

void	check_char(t_mlx *mlx, int y, int x)
{
	char	c;

	c = mlx->file.point[y][x];
	if (c == 'C')
	{
		mlx->elements.collectible.count++;
		mlx->elements.collectible.total_count++;
	}
	else if (c == 'E')
	{
		mlx->elements.exit.x = x;
		mlx->elements.exit.y = y;
		mlx->elements.exit.count++;
	}
	check_next_char(mlx, y, x);
}

void	check_limit(t_mlx *mlx)
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
	else if (mlx->elements.ia.count > MAX_IA_LIMIT && \
		MAX_IA_LIMIT != -1)
		ft_exit(mlx, ERROR_TO_MANY_IA, 1);
	else if (mlx->elements.ia.count < MIN_IA_LIMIT)
		ft_exit(mlx, ERROR_NOT_ENOUGH_IA, 1);
	printf("IA COUNTER: %d\n", mlx->elements.ia.count);
	send_error(mlx);
}
#endif
