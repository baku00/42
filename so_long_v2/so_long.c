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

	mlx.error_message = init_error_message();
	mlx.message = init_message();
	if (argc != 2)
		error(mlx.error_message.wrong_count_argument);
	init_game(&mlx, argv[1]);
	mlx_key_hook(mlx.window.ptr, hook, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
