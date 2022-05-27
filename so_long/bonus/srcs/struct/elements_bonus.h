/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:38 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 17:45:58 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_BONUS_H
# include "../header_bonus.h"
# define ELEMENTS_BONUS_H

typedef struct s_ia
{
	void		*img;
	void		*img_2;
	int			count;
}	t_ia;

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
