/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:38 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/22 03:47:34 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H
# include "../header.h"
# ifdef WITH_BONUS
#  include "./elements_bonus.h"
# endif

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

# ifdef WITH_BONUS

typedef struct s_elements
{
	t_collectible	collectible;
	t_exit			exit;
	t_player		player;
	t_wall			wall;
	t_empty			empty;
	t_ia			ia;
}	t_elements;
# endif
# ifndef WITH_BONUS

typedef struct s_elements
{
	t_collectible	collectible;
	t_exit			exit;
	t_player		player;
	t_wall			wall;
	t_empty			empty;
}	t_elements;
# endif
#endif
