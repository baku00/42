/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:34:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/13 19:20:33 by my_name_         ###   ########.fr       */
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
	if (env == get_first_env(next))
		((t_info *) get_first_env(next)->info)->first = env->next;
	if (next)
		next = get_first_env(next);
	else if (prev)
		prev = get_first_env(prev);
	free_env(env);
	((t_info *) next->info)->length -= 1;
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

static t_export	*init_export()
{
	t_export	*export;

	export = ft_calloc(sizeof(t_export), 1);
	if (!export)
		return (NULL);
	export->key = create_string("");
	export->value = create_string("");
	export->next = NULL;
	export->prev = NULL;
	export->n = 0;
	return (export);
}

void	register_export(t_export **exports, t_export *export)
{
	int	strncmp;
	int	length;
	char	*string;

	length = get_string_length(export->key);
	string = get_string(export->key);
	strncmp = ft_strncmp(get_string((*exports)->key), string, length);
	if (strncmp > 0)
	{
		(*exports)->prev = export;
		export->next = (*exports);
		return ;
	}
	while ((*exports)->next && strncmp < 0)
	{
		(*exports) = (*exports)->next;
		strncmp = ft_strncmp(get_string((*exports)->key), string, length);
	}
	export->next = (*exports)->next;
	(*exports)->next = export;
	export->prev = (*exports);
}

t_export	*create_export_entry(char *key, char *value)
{
	t_export	*export;

	export = init_export();
	if (!export)
		return (NULL);
	free_string(export->key);
	free_string(export->value);
	export->key = create_string(key);
	export->value = create_string(value);
	return (export);
}

t_export	*generate_export(t_export *export, t_env *env, int env_length)
{
	t_string	*export_key;
	t_string	*env_key;
	int			strncmp;

	export = init_export();
	if (!export)
		return (NULL);
	while (env->next)
	{
		export_key = (t_string *) export->key;
		env_key = (t_string *) env->key;
		if (!get_string(export->key)[0])
			strncmp = ft_strncmp(env_key->value, export_key->value, env_key->length);
		else
			strncmp = ft_strncmp(export_key->value, env_key->value, export_key->length);
		if (strncmp > 0)
			export = (t_export *) copy_env(env);
		env = env->next;
	}
	env = get_first_env(env);
	env = remove_env(export, env, env_length);
	if (env && env->next)
		export->next = generate_export(NULL, env, env_length - 1);
	return (export);
}