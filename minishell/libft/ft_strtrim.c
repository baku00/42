/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:37:22 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:01:59 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_array(const char c, char const *set)
{
	char	*get;

	get = (char *) set;
	while (*get)
		if (*get++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		start;
	int		end;

	if (!str)
		return (0);
	i = 0;
	while (ft_in_array(str[i], set))
		i++;
	start = i;
	i = ft_strlen(str) - 1;
	while (ft_in_array(str[i], set))
		i--;
	end = i + 1;
	if (end == 0)
		return (ft_substr(str, 0, 0));
	return (ft_substr(str, start, end - start));
}
