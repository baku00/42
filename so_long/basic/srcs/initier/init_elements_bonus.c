/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:54:51 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/22 03:18:12 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#ifdef WITH_BONUS

static void	init_wall_empty_collectible(t_elements *e)
{
	t_wall			_wall;
	t_empty			_empty;
	t_collectible	_collectible;

	_wall.img = NULL;
	_wall.count = 0;
	_empty.img = NULL;
	_collectible.img = NULL;
	_collectible.count = 0;
	_collectible.total_count = 0;
	e->wall = _wall;
	e->empty = _empty;
	e->collectible = _collectible;
}

static t_exit	init_exit(void)
{
	t_exit	_exit;

	_exit.img = NULL;
	_exit.is_enabled = 0;
	_exit.x = 0;
	_exit.y = 0;
	_exit.count = 0;
	return (_exit);
}

static t_player	init_player(void)
{
	t_player	_player;

	_player.img = NULL;
	_player.x = 0;
	_player.y = 0;
	_player.current_x = 0;
	_player.current_y = 0;
	_player.count = 0;
	_player.movement = 0;
	return (_player);
}

static t_ia	init_ia(void)
{
	t_ia	_ia;

	_ia.img = NULL;
	_ia.img_2 = NULL;
	_ia.count = 0;
	return (_ia);
}

t_elements	init_elements(void)
{
	t_elements	elements;

	init_wall_empty_collectible(&elements);
	elements.exit = init_exit();
	elements.player = init_player();
	elements.ia = init_ia();
	return (elements);
}
#endif
