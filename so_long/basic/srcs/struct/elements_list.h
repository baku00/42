/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:38 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 21:48:04 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_LIST_H
# define ELEMENTS_LIST_H
# include "../header.h"

typedef struct s_wall
{
	void		*img;
	int			count;
}	t_wall;

typedef struct s_exit
{
	void		*img;
	int			is_enabled;
	int			x;
	int			y;
	int			count;
}	t_exit;

typedef struct s_collectible
{
	void		*img;
	int			count;
	int			total_count;
}	t_collectible;

typedef struct s_empty
{
	void		*img;
}	t_empty;

typedef struct s_player
{
	void		*img;
	int			x;
	int			y;
	int			current_x;
	int			current_y;
	int			count;
	int			movement;
}	t_player;
#endif
