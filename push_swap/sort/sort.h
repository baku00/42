/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:16:17 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/06 16:15:09 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "../main.h"

typedef struct s_sort
{
	int	*a;
	int	a_counter;
	int	*b;
	int	b_counter;
	int	max_length;
}	t_sort;

void	sort_small(t_sort sort);
void	sort_big(t_sort sort);
int		*s(int *list, char c, int display);
int		*r(int *l, int counter, char c, int display);
int		*rr(int *l, int counter, char c, int display);
t_sort	pb(t_sort sort);
t_sort	pa(t_sort sort);

#endif