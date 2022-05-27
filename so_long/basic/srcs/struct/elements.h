/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:38 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 21:49:44 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H
# include "../header.h"
# include "./elements_list.h"
# ifdef WITH_BONUS
#  include "../../../bonus/srcs/struct/elements_bonus.h"
# else

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
