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

char	*valid_map_shape(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->map.wall = 0;
	mlx->map.empty = 0;
	mlx->map.player = 0;
	mlx->map.coin = 0;
	mlx->map.exit = 0;
	mlx->map.line.length = 0;
	mlx->map.line_counter = 0;
	while (mlx->map.line.line[i])
	{
		contains_object(mlx->map.line.line[i], mlx);
		if (!mlx->map.line.length)
		{
			mlx->map.line.length = ft_strlen(mlx->map.line.line[i]);
			mlx->map.char_to_string[0] = mlx->define.wall;
			if (!is_n_only(mlx->map.line.line[i], mlx->map.char_to_string, mlx->map.line.length))
			{
				return (mlx->error_message.wrong_map_close);
			}
			if (!is_n_only(mlx->map.line.line[i], mlx->map.accepted_chars, mlx->map.line.length))
			{
				return (mlx->error_message.wrong_char_map);
			}
		}
		else
		{
			if (mlx->map.line.length != ft_strlen(mlx->map.line.line[i]))
			{
				return (mlx->error_message.wrong_map_width);
			}
			if (!is_at(mlx->map.line.line[i], mlx->define.wall, 0) || !is_at(mlx->map.line.line[i], mlx->define.wall, mlx->map.line.length - 1))
			{
				return (mlx->error_message.wrong_map_close);
			}
			if (!is_n_only(mlx->map.line.line[i], mlx->map.accepted_chars, mlx->map.line.length))
			{
				return (mlx->error_message.wrong_char_map);
			}
		}
		mlx->map.line_counter++;
		i++;
	}
	if (!is_n_only(mlx->map.line.line[i - 1], mlx->map.char_to_string, mlx->map.line.length - 1))
	{
		return (mlx->error_message.wrong_map_close);
	}
	if (mlx->map.line_counter == mlx->map.line.length)
	{
		return (mlx->error_message.wrong_map_size);
	}
	if (!valid_contains(mlx->map.contains))
	{
		return (mlx->error_message.missing_char);
	}
	mlx->map.width = mlx->map.line.length;
	mlx->map.height = mlx->map.line_counter;
	return (0);
}
