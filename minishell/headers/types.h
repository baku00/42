/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:56:59 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/20 22:13:03 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "headers.h"

typedef struct s_export
{
	char	*export;
	char	*key;
	char	*value;
	int		type;
	void	*next;
}	t_export;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		type;
	void	*next;
}	t_env;

typedef struct s_path
{
	char	*full_path;
	char	*parent_path;
	char	*current;
	void	*parent;
	void	*child;
}	t_path;

typedef struct s_result
{
	int		line_number;
	char	*line;
	void	*next;
}	t_result;

typedef struct s_cmd
{
	char	*cmd;
	char	*args;
	int		splitter;
	void	*next;
	void	*result;
}	t_cmd;

typedef struct s_history
{
	char	*cmd_executed;
	void	*cmd;
	void	*next;
	void	*prev;
}	t_history;

typedef struct s_minishell
{
	t_export	export;
	t_env		env;
	t_path		path;
	t_history	history;
	char		*cmd;
	int			have_to_exit;
}	t_minishell;

#endif