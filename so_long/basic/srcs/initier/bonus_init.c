/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:54:51 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/19 22:21:54 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef WITH_BONUS
#include "../../so_long.h"

t_mlx	init_mlx(void)
{
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	printf("THIS IS A BONUS\n");
	t_mlx	_mlx;

	_mlx.ptr = NULL;
	_mlx.window = init_window();
	_mlx.elements = init_elements();
	_mlx.file = init_file();
	return (_mlx);
}
#endif
