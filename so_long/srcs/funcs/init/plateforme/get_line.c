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

#include "../../../../so_long.h"

t_line	get_line(t_mlx *mlx)
{
	t_line	lines;
	char	*line;
	char	*l;

	l = "";
	line = ft_calloc(1, sizeof(char));
	while (l)
	{
		line = ft_strjoin_free(line, l);
		l = get_next_line(mlx->map.fd);
	}
	lines.line = ft_split(line, '\n');
	return (lines);
}
