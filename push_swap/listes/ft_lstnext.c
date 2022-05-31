/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:41:23 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/30 19:00:16 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstnext(t_list **lst)
{
	t_list	*new;
	int	nb_elem;

	if (!(*lst) || !(*lst)->next)
	{
		if (!(*lst)->next)
			*lst = NULL;
		return ;
	}
	nb_elem = (*lst)->nb_elem;
	new = (*lst)->next;
	new->nb_elem = nb_elem - 1;
	ft_lstdelone(*lst, NULL);
	*lst = new;
}
