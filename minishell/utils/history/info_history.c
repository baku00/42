/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:33:32 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/15 23:33:55 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_info_history	*get_info_history(t_history *history)
{
	return (history->info);
}

t_history	*get_first_history(t_history *history)
{
	return (get_info_history(history)->first);
}

t_history	*get_last_history(t_history *history)
{
	return (get_info_history(history)->last);
}

t_history	*get_current_history(t_history *history)
{
	return (get_info_history(history)->current);
}
