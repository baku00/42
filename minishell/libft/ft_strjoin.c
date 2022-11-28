/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:37:22 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/28 04:03:13 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_join
{
	char	*str;
	int		i;
	int		j;
	int		len;
}	t_join;

char	*ft_strjoin(char *s1, char *s2)
{
	t_join	join;

	if (!s1 || !s2)
		return (0);
	join.str = ft_calloc(ft_strlen((char *) s1) + \
			ft_strlen((char *) s2) + 1, sizeof(char));
	if (!join.str)
		return (0);
	join.i = 0;
	while (join.str[join.i])
		join.str[join.i++] = '\0';
	join.i = 0;
	join.j = 0;
	join.len = ft_strlen(s1);
	while (join.i < join.len)
		join.str[join.j++] = s1[join.i++];
	join.i = 0;
	join.len = ft_strlen(s2);
	while (join.i < join.len)
		join.str[join.j++] = s2[join.i++];
	free(s1);
	free(s2);
	return (join.str);
}
