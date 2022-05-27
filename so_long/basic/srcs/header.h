/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:26 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/27 21:38:41 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../so_long.h"
# include "./struct/elements.h"
# include "./struct/file.h"
# include "./struct/window.h"
# include "./headers/errors.h"
# include "./headers/messages.h"
# include "./headers/collectible.h"
# include "./headers/keys_linux.h"
# include "./headers/exit.h"
# include "./headers/items.h"
# include "./headers/player.h"
# include "./headers/empty.h"
# include "./headers/wall.h"
# ifdef WITH_BONUS
#  include "../../bonus/srcs/header_bonus.h"
# endif
#endif
