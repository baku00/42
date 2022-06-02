/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 01:56:58 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_lists
{
	int	*a;
	int	a_counter;
	int	*b;
	int	b_counter;
}	t_lists;

typedef struct s_element
{
	int	*a;
	int	*b;
}	t_element;

typedef struct s_push_swap
{
	int	*a;
	int	*b;
}	t_push_swap;
#endif