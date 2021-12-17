/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

t_define	init_define()
{
	t_define	define;

	define.empty = '0';
	define.wall = '1';
	define.collectible = 'C';
	define.exit = 'E';
	define.start_player_position = 'P';
	return (define);
}
