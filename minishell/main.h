/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:00:10 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:00:10 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "headers/includes.h"

typedef struct s_main
{
	char	**cmds;
	char	*cmd;
	char	**path;
	char	*full_path;
	int		exit;
}	t_main;

typedef struct s_cmd_arguments
{
	char	*args;
	void	*next;
}	t_cmd_arguments;

typedef struct s_command
{
	char			*cmd;
	t_cmd_arguments	*args;
}	t_command;

int	main(int argc, char **argv);

#endif
