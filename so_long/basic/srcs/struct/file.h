/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:41 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:36:42 by dgloriod         ###   ########.fr       */
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
