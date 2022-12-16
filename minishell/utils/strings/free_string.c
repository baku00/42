/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:40:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/13 00:41:12 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	free_string(t_string *string)
{
	if (!string)
		return ;
	free(string->value);
	free(string);
}