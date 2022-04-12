/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:18 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/12 03:07:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_first_window(t_mlx *mlx)
{
	t_window	window;

	window.height = 0;
	window.width = 0;
	window.title = NULL;
	window.ptr = 0;
	mlx->window = window;
}

static void	create_instance(t_mlx *mlx)
{
	t_elements		elements;
	t_collectible	collectible;
	t_exit			exit;
	t_player		player;
	t_wall			wall;
	t_empty			empty;

	collectible.count = 0;
	collectible.total_count = 0;
	collectible.img = NULL;
	exit.is_enabled = 0;
	exit.count = 0;
	exit.img = NULL;
	wall.count = 0;
	wall.img = NULL;
	player.x = 0;
	player.y = 0;
	player.movement = 0;
	player.count = 0;
	player.img = NULL;
	empty.img = NULL;
	elements.collectible = collectible;
	elements.exit = exit;
	elements.wall = wall;
	elements.player = player;
	elements.empty = empty;
	mlx->elements = elements;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		ft_exit(&mlx, ERROR_SYNTAXE, 1);
	mlx.ptr = NULL;
	create_first_window(&mlx);
	create_instance(&mlx);
	printf("Analyse du fichier\n");
	ft_check_file(&mlx, argv[1]);
	printf("Création de la map\n");
	ft_create_map(&mlx);
	printf("Placement des images\n");
	set_images(&mlx);
	mlx_key_hook(mlx.window.ptr, key_hook, &mlx);
	mlx_hook(mlx.window.ptr, 17, 1L << 17, mlx_close, &mlx);
	printf("\n\n\nDébut du jeu\n");
	mlx_loop(mlx.ptr);
	return (0);
}
