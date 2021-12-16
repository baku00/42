/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:06 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:22:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_mlx mlx;

	(void) argc;
	if (argc != 2)
		error();
	init_game(&mlx, argv[1]);
	printf("%s, %d\n", (char *)mlx.wall.img, ft_isalpha('a'));
	int height = 500;
	int width = 500;
	void *window = mlx_new_window(mlx.ptr, width, height, "SO_LONG");
	mlx_loop(mlx.ptr);
	return 0;
}
