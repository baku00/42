/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:11:28 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/20 23:13:41 by my_name_         ###   ########.fr       */
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
