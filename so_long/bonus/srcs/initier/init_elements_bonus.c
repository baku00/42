/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:54:51 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 17:17:15 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../basic/so_long.h"
#ifdef WITH_BONUS

t_ia	init_ia(void)
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
