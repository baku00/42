/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:59:11 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/24 00:25:39 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_path	get_default_path()
{
	t_path	path;

	path.full_path = ft_strdup("/");
	path.parent_path = ft_strdup("/");
	path.current = ft_strdup("/");
	path.is_root = 1;
	path.prev = NULL;
	path.next = NULL;
	path.last = NULL;
	return (path);
}

static t_path	*generate_path(t_path *prev, char **paths, int i)
{
	t_path	*path;

	if (!prev)
		return (NULL);
	path = ft_calloc(sizeof(t_path), 1);
	if (!path)
		return (NULL);
	path->full_path = ft_strdup("/");
	if (prev->prev)
		path->full_path = ft_strjoin(prev->full_path, "/");
	path->full_path = ft_strjoin(path->full_path, paths[i]);
	path->parent_path = ft_strdup(prev->full_path);
	path->current = ft_strdup(paths[i]);
	path->is_root = 0;
	path->prev = prev;
	if (paths[i + 1])
		path->next = generate_path(path, paths, i + 1);
	else
		path->next = NULL;
	return (path);
}

void	create_path(t_minishell *minishell, char *dir)
{
	char	**paths;

	paths = ft_split(dir, '/');
	if (!paths)
		return ;
		// return (free_all(minishell));
	(&minishell->path)->next = generate_path(&minishell->path, paths, 0);
}