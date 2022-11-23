/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:16:06 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/23 00:17:27 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	free_list(void *list)
{
	void	*last;

	while (list)
	{
		last = list;
		list = list->next;
		free(last);
		last = NULL;
	}
}