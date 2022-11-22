/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:59:11 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/23 00:05:11 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_path	*create_path_from_directory(t_path parent, char *directory)
{
	char	**paths;
	t_path	*path;

	paths = ft_split(directory, '/');
}

t_path	create_path(t_path parent, char *path)
{
	t_path	path;

	if (path[0] != '/')
		path.full_path = ft_strjoin(ft_strdup(parent.full_path), "/");
	path.full_path = ft_strjoin(ft_strdup(parent.full_path), path);
	path.parent_path = ft_strdup(parent.full_path);
	path.current = ft_strdup(path);
}