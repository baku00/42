/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/10/30 23:17:14 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
#define LISTS_H

/*
	int *a			la liste a
	int a_counter	le nombre d'éléments présent dans liste a
	int *b			la liste b
	int b_counter	le nombre d'éléments présent dans liste b
*/
typedef struct s_lists
{
	int *a;
	int a_counter;
	int *b;
	int b_counter;
} t_lists;
#endif
