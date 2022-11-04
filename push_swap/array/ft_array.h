/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:57:02 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 16:04:30 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H
# include "../main.h"

char	**ft_array_dup(char **array);
int		*ft_int_array_dup(int *array, int length);
char	*array_to_string(char **array);
int		ft_array_length(char **argv);
void	free_array(char **argv, int i);

#endif