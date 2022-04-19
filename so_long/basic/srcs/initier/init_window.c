/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:54:51 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/19 21:41:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_window	init_window(void)
{
	t_window	_window;

	_window.ptr = NULL;
	_window.title = NULL;
	_window.height = 0;
	_window.width = 0;
	return (_window);
}
