/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:33:30 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:01:59 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	if (!s)
		return (0);
	if (len > (unsigned long) ft_strlen(s))
		result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	else
		result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	result[0] = ""[0];
	result[1] = '\0';
	if ((size_t) start > ft_strlen(s))
		return (result);
	i = 0;
	if (!result)
		return (0);
	while (i < len && s[start])
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
