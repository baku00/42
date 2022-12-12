/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:34:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/12 02:56:20 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

static t_env	*clear_env(t_env *env)
{
	t_env	*prev;
	t_env	*next;

	prev = env->prev;
	next = env->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (next)
		next = ((t_info *) next->info)->first;
	else if (prev)
		prev = ((t_info *) prev->info)->first;
	return  (next);
}

static t_env	*remove_env(t_export *export, t_env *env, int length)
{
	int	i;

	i = -1;
	while (++i < length && export->n != env->n)
		env = env->next;
	if (export->n == env->n)
		env = clear_env(env);
	return (get_first_env(env));
}

t_export	*generate_export(t_export *export, t_env *env, int env_length)
{
	t_string	*key;
	t_string	*value;
	int			strncmp;

	export = (t_export *) env;
	if (!export)
		return (NULL);
	while (env->next)
	{
		env = env->next;
		key = (t_string *) export->key;
		value = (t_string *) env->key;
		strncmp = ft_strncmp(key->value, value->value, key->length);
		if (strncmp > 0)
			export = (t_export *) env;
	}
	env = ((t_info *) env->info)->first;
	env = remove_env(export, env, env_length);
	printf("%d\n", env_length);
	if (env_length < 0)
	{
		print_env(env);
		printf("\n\nExport\n");
		print_env((t_env *) export);
		exit(0);
	}
	if (env && env->next)
		export->next = generate_export((t_export *) env, env, env_length - 1);
	return (export);
}