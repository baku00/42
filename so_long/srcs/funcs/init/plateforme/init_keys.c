/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/21 11:51:50 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

t_keys	init_keys(void)
{
	t_keys	keys;

	keys.escape = 53;
	keys.up = 13;
	keys.down = 1;
	keys.left = 0;
	keys.right = 2;
	return (keys);
}
