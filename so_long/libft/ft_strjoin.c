/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:37:22 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/12 02:56:30 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i0_j1_len2[3];

	if (!s1 || !s2)
		return (0);
	str = ft_calloc(ft_strlen((char *) s1) + \
			ft_strlen((char *) s2) + 1, sizeof(char));
	if (!str)
		return (0);
	i0_j1_len2[0] = 0;
	while (str[i0_j1_len2[0]])
		str[i0_j1_len2[0]++] = '\0';
	i0_j1_len2[0] = 0;
	i0_j1_len2[1] = 0;
	i0_j1_len2[2] = ft_strlen(s1);
	while (i0_j1_len2[0] < i0_j1_len2[2])
		str[i0_j1_len2[1]++] = s1[i0_j1_len2[0]++];
	i0_j1_len2[0] = 0;
	i0_j1_len2[2] = ft_strlen(s2);
	while (i0_j1_len2[0] < i0_j1_len2[2])
		str[i0_j1_len2[1]++] = s2[i0_j1_len2[0]++];
	free(s1);
	free(s2);
	return (str);
}
