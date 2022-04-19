/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:54:51 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/19 21:41:47 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_file	init_file(void)
{
	t_file	_file;

	_file.name = NULL;
	_file.content = NULL;
	_file.line = NULL;
	_file.width = 0;
	_file.height = 0;
	_file.point = 0;
	_file.fd = 0;
	_file.content_length = 0;
	return (_file);
}
