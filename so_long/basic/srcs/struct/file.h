/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:41 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/01 01:10:48 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "../header.h"

typedef struct s_file
{
	char	*name;
	char	*content;
	char	*line;
	size_t	width;
	size_t	height;
	int		**point;
	int		fd;
	size_t	content_length;
}	t_file;
#endif
