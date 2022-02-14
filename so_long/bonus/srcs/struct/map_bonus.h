/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:45 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:36:46 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H
# include "../header_bonus.h"

typedef struct s_width
{
	int			width;
}	t_width;

typedef struct s_BONUS_Height
{
	int			height;
}	t_BONUS_Height;

typedef struct s_map
{
	int				**point;
	t_width			width;
	t_BONUS_Height		height;
}	t_map;
#endif
