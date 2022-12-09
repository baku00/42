/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:11:28 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/03 17:13:43 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_result	init_result()
{
	t_result	result;

	result.line_number = 0;
	result.line = NULL;
	result.next = NULL;
	return (result);
}

t_info_env	init_info_env()
{
	t_info_env	info_env;

	info_env.last = NULL;
	return (info_env);
}