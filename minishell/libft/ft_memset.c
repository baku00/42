/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:37:22 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:01:59 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, unsigned char c, int len)
{
	int		i;
	char	*string;

	i = 0;
	string = b;
	while (i < len)
	{
		string[i] = c;
		i++;
	}
	b = string;
	return (b);
}
