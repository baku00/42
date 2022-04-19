/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:54:51 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/19 21:41:38 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_mlx	init_mlx(void)
{
	t_mlx	_mlx;

	_mlx.ptr = NULL;
	_mlx.window = init_window();
	_mlx.elements = init_elements();
	_mlx.file = init_file();
	return (_mlx);
}
