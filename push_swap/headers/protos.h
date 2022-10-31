/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/10/31 17:08:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H
# include "../push_swap.h"

int			main(int argc, char **argv);
void		*ft_calloc(size_t count, size_t size);
bool		check_number_arguments(int argc);
t_argument	parse_arguments(int argc, char **argv);
int			*convert_to_numbers(t_argument argument);
int			*get_index(int *numbers, int counter);
int			*r(int *l, int counter);
int			*rr(int *l, int counter);
int			*sa(int *a);
t_lists		p(int *l1, int *l2, int counter1, int counter2);
void		sort_small_stack(t_lists lists);
int			find_min(int *stack, int counter);
bool		is_sorted(int *numbers, int counter);
void		freeall(t_argument argument, t_lists lists);
#endif
