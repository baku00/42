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

#ifndef MAP_H
# define MAP_H
# include "../header.h"

typedef struct s_width
{
	int			width;
}	t_width;

typedef struct s_height
{
	int			height;
}	t_height;

typedef struct s_map
{
	int				**point;
	t_width			width;
	t_height		height;
}	t_map;
#endif
