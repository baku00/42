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
	(void) argc;
	(void) argv;
	t_mlx mlx;
	init_game(&mlx, "hello");
	printf("%d, %d\n", mlx.test, ft_isalpha('a'));
	return 0;
}
