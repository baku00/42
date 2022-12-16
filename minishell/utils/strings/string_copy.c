/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:06:00 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/13 01:08:26 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

t_string	*string_copy(t_string *str)
{
	t_string	*copy;

	if (!str)
		return (NULL);
	copy = create_string(str->value);
	return (copy);
}