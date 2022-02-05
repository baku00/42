/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:58:33 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "srcs/header.h"
# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include "srcs/struct/window.h"
typedef struct s_mlx
{
	void			*ptr;
	t_window		window;
	t_elements		elements;
	t_file			file;
}	t_mlx;
# include "srcs/protos.h"

#endif
