/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:34:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/11 04:30:23 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

static t_export	*init_export()
{
	t_export	*export;

	export = ft_calloc(sizeof(t_export), 1);
	if (!export)
		return (NULL);
	export->key = NULL;
	export->value = NULL;
	export->next = NULL;
	export->prev = NULL;
	export->n = 0;
	return (export);
}

t_export	*generate_export(t_env *env, t_info *info_export, int memory)
{
	t_export	*export;
	int			length;

	export = init_export();
	if (!export)
		return (NULL);
	while (env->next)
	{
		length = ft_strlen(((t_string *) export->key)->value);
		memory = ft_strncmp(((t_string *) export->key)->value, ((t_string *) env->key)->value, length);
	}
	return ((t_export *) env);
}