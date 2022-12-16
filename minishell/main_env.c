/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:54:31 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/13 18:59:58 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_info	info_env;
	t_export	*export;

	(void) argc;
	(void) argv;
	(void) envp;
	(void) env;
	// int i = -1;
	// while (envp[++i])
	// 	printf("[%d]: %s\n", i, envp[i]);
	// printf("\n\n\n\n\n");
	info_env.first = NULL;
	info_env.last = NULL;
	info_env.length = 0;
	env = generate_env(NULL, envp, &info_env, 0);
	// print_env((t_env *) env);
	// print_env(env);
	(void) env;
	export = (t_export *) env;
	// print_env(env);
	// printf("\n");
	export = generate_export(NULL, env, info_env.length);
	(void) export;
	register_export(&export, create_export_entry("Hello", "123"));
	print_env((t_env *) export);
	return (0);
}
