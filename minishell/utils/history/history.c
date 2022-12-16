/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:27:50 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/15 23:33:52 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	add_back_history(t_history **histories, t_history *history)
{
	(*histories) = get_last_history((*histories));
	(*histories)->next = history;
	history->prev = (*histories);
}

void	add_front_history(t_history **histories, t_history *history)
{
	(*histories) = get_first_history((*histories));
	(*histories)->prev = history;
	history->next = (*histories);
}
