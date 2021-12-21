/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/21 13:28:18 by dgloriod         ###   ########.fr       */
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
	if (mlx->map.fd < 0)
		error("Map invalid");
	while (l)
	{
		line = ft_strjoin_free(line, l);
		l = get_next_line(mlx->map.fd);
	}
	lines.line = ft_split(line, '\n');
	return (lines);
}
