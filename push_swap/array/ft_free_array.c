/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:56:53 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/06 16:08:08 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void	free_array(char **argv, int i)
{
	while (--i >= 0)
		free(argv[i]);
	free(argv);
}
