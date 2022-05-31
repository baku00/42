/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:41:23 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/29 23:05:56 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int))
{
	(void) lst;
	(void) f;
	(void) del;
	// t_list	*first;
	// t_list	*new;
	//
	// if (!f || !del)
	// 	return (NULL);
	// first = NULL;
	// while (lst)
	// {
	// 	new = ft_lstnew((*f)(lst->nbr));
	// 	if (!new)
	// 	{
	// 		while (first)
	// 		{
	// 			new = first->next;
	// 			(*del)(first->nbr);
	// 			free(first);
	// 			first = new;
	// 		}
	// 		lst = NULL;
	// 		return (NULL);
	// 	}
	// 	ft_lstadd_back(&first, new);
	// 	lst = lst->next;
	// }
	// return (first);
	return (NULL);
}
