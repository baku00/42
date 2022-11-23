/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:59:11 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/23 20:29:35 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_path	generate_path(t_path prev, char **paths, int i)
{
	t_path	path;

	path.full_path = ft_strjoin(ft_strdup(prev->full_path), paths[i]);
	path.parent_path = prev->full_path;
	path.current = paths[i];
	path.prev = prev;
	if (paths[i + 1])
		path.next = generate_path(path, paths, i + 1);
	else
		path.next = NULL;
	return (path);
}

void	create_path(t_minishell *minishell, char *path)
{
	t_path	*path;
	char	**paths;

	paths = ft_split(path, '/');
	if (!paths)
		return (NULL);
	minishell->path->next = generate_path(minishell->path, paths, 0);
	path = minishell->path;
	while (path)
	{
		printf("%s\n", path->full_path);
		path = path->next;
	}
}