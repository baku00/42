/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 02:16:10 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

#include "../push_swap.h"

int			main(int argc, char **argv);
void		*ft_calloc(size_t count, size_t size);
bool		check_number_arguments(int argc);
t_argument	parse_arguments(int argc, char **argv);
int			*convert_to_numbers(t_argument argument);
int		*get_index(int *numbers, int counter);
void	sa(t_list *a);
t_element	ra(int *a, int counter);
t_element	pa(int *a, int *b, int counter);
t_element	pb(int *a, int *b, int counter);
void	rra(t_list *a);
#endif
