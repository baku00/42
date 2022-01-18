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

void	verify_map_filename(t_mlx *mlx, char *filename)
{
	size_t	length;
	char	*substr;

	length = ft_strlen(filename);
	substr = ft_substr(filename, length - 4, length);
	if (ft_strncmp(substr, ".ber", 4))
	{
		free(substr);
		error(mlx->error_message.wrong_filename);
	}
	free(substr);
}
