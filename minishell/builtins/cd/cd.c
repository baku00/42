/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:20:40 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/23 20:29:55 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

static void	set_path(t_minishell *minishell, char dir)
{
	(void) minishell;
	(void) dir;
	free_list(minishell->path);
	minishell->path = NULL;
	if (dir == HOME_CHAR)
		minishell->path = create_path(minishell, getenv("HOME"));
	else if (dir == ROOT_CHAR)
		minishell->path = create_path(minishell, "/");
}

static int	is_main_directory(char dir)
{
	return (dir == HOME_CHAR || dir == ROOT_CHAR);
}

int	exec_cd(t_minishell *minishell, char *path)
{
	(void) minishell;
	if (!dir_exist(path))
		return (0);
	if (is_main_directory(path[0]))
		set_path(minishell, path[0]);
	// char	**paths;

	// paths = ft_split(path, '/');
	// if (!paths)
	// 	return ;
	// if (is_absolute_path(path))
	// 	cd_update_path(minishell, paths, 1);
	return (1);
}
