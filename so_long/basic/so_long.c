/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:18 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 18:58:36 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx = init_mlx();
	if (argc != 2)
		ft_exit(&mlx, ERROR_SYNTAXE, 1);
	printf("Analyse du fichier\n");
	ft_check_file(&mlx, argv[1]);
	printf("Création de la map\n");
	ft_create_map(&mlx);
	printf("Placement des images\n");
	set_images(&mlx);
	mlx_key_hook(mlx.window.ptr, key_hook, &mlx);
	mlx_hook(mlx.window.ptr, 17, 1L << 17, mlx_close, &mlx);
	printf("\n\n\nDébut du jeu\n");
	print_ath(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
