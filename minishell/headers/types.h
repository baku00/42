/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:56:59 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/11 04:09:26 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "headers.h"

typedef struct s_string
{
	char	*value;
	int		length;
	int		error;
}	t_string;

typedef struct s_info
{
	int		length;
	void	*first;
	void	*last;
	void	*save_after;
}	t_info;

typedef struct s_env
{
	t_string	*key;
	t_string	*value;
	int			n;
	void	*info;
	void	*next;
	void	*prev;
}	t_env;

typedef struct s_export
{
	t_string	*key;
	t_string	*value;
	int			n;
	void		*info;
	void		*next;
	void		*prev;
}	t_export;

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

typedef struct s_args
{
	char	*cmd;
	char	*arg;
	char	*substr;
	void	*next;
	void	*prev;
	int		splitter;
	int		double_char;
	char	*result;
}	t_args;

typedef struct s_builtin
{
	t_string	*string;
	char		*(*function)(void *);
	int			return_type;
}	t_builtin;

typedef struct s_builtins
{
	t_builtin	*echo;
	t_builtin	*env;
	t_builtin	*export;
	t_builtin	*unset;
	t_builtin	*pwd;
	t_builtin	*cd;
	t_builtin	*exit;
}	t_builtins;

typedef struct t_minishell
{
	t_env		*env;
	t_history	*history;
	t_args		*args;
	t_builtins	builtins;
	char		*read;
	int			have_to_exit;
}	t_minishell;

#endif