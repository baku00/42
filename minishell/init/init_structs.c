/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:11:28 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/23 20:20:58 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_export	init_export()
{
	t_export	export;

	export.export = NULL;
	export.key = NULL;
	export.value = NULL;
	export.type = UNDEFINED_TYPE;
	export.next = NULL;
	return (export);
}

t_env	init_env()
{
	t_env	env;

	env.key = NULL;
	env.value = NULL;
	env.type = UNDEFINED_TYPE;
	env.next = NULL;
	return (env);
}

t_path	init_path()
{
	t_path	path;

	path.full_path = "/";
	path.parent_path = "/";
	path.current = "/";
	path.prev = NULL;
	path.next = NULL;
	return (path);
}

t_cmd	init_cmd()
{
	t_cmd	cmd;

	cmd.cmd = NULL;
	cmd.args = NULL;
	cmd.splitter = UNDEFINED_SPLITTER;
	cmd.next = NULL;
	cmd.result = NULL;
	return (cmd);
}

t_history	init_history()
{
	t_history	history;

	history.cmd_executed = NULL;
	history.cmd = NULL;
	history.next = NULL;
	history.prev = NULL;
	return (history);
}
