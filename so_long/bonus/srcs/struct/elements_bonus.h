/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:38 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:36:39 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_BONUS_H
# define ELEMENTS_BONUS_H
# include "../header_bonus.h"

typedef struct s_wall
{
	void		*img;
	int			count;
}	t_wall;

typedef struct s_ia
{
	void		*img;
	void		*img_2;
	int			count;
}	t_ia;

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

typedef struct s_elements
{
	t_collectible	collectible;
	t_exit			exit;
	t_player		player;
	t_wall			wall;
	t_empty			empty;
	t_ia			ia;
}	t_elements;
#endif
