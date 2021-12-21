/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/21 13:32:53 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../../so_long.h"

static char	*first(t_mlx *mlx, int i)
{
	mlx->map.line.length = ft_strlen(mlx->map.line.line[i]);
	mlx->map.char_to_string[0] = mlx->define.wall;
	if (!is_n_only(mlx->map.line.line[i], \
		mlx->map.char_to_string, mlx->map.line.length))
		return (mlx->error_message.wrong_map_close);
	if (!is_n_only(mlx->map.line.line[i], \
		mlx->map.accepted_chars, mlx->map.line.length))
		return (mlx->error_message.wrong_char_map);
	return (0);
}

static char	*second(t_mlx *mlx, int i)
{
	if (mlx->map.line.length != ft_strlen(mlx->map.line.line[i]))
		return (mlx->error_message.wrong_map_width);
	if (!is_at(mlx->map.line.line[i], mlx->define.wall, 0) \
	|| !is_at(mlx->map.line.line[i], mlx->define.wall, \
		mlx->map.line.length - 1))
		return (mlx->error_message.wrong_map_close);
	if (!is_n_only(mlx->map.line.line[i], \
		mlx->map.accepted_chars, mlx->map.line.length))
		return (mlx->error_message.wrong_char_map);
	return (0);
}

static char	*last_check(t_mlx *mlx, int i)
{
	if (!is_n_only(mlx->map.line.line[i - 1], \
		mlx->map.char_to_string, mlx->map.line.length - 1))
		return (mlx->error_message.wrong_map_close);
	if (mlx->map.line_counter == mlx->map.line.length)
		return (mlx->error_message.wrong_map_size);
	if (!valid_contains(mlx->map.contains))
		return (mlx->error_message.missing_char);
	if (mlx->map.contains.player != 1)
		return ("Un seul joueur est necessaire");
	return (0);
}

char	*valid_map_shape(t_mlx *mlx)
{
	int		i;
	char	*shape;

	i = 0;
	mlx->map.line.length = 0;
	if (!mlx->map.line.line[0])
		error("La map contient une erreur");
	while (mlx->map.line.line[i])
	{
		contains_object(mlx->map.line.line[i], mlx);
		if (!mlx->map.line.length)
			shape = first(mlx, i);
		else
			shape = second(mlx, i);
		mlx->map.line_counter++;
		i++;
	}
	shape = last_check(mlx, i);
	mlx->map.width = mlx->map.line.length;
	mlx->map.height = mlx->map.line_counter;
	return (shape);
}
