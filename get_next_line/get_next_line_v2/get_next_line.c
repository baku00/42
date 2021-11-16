/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:33 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/16 14:38:26 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strfchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (ft_substr(str, 0, i));
	return (0);
}

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if ((char) str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	if ((char) str[i] == (char) c)
		return (&str[i]);
	return (0);
}

char	*get_next_line(int fd)
{
	int	i;
	int	ret;
	static char *buf;
	char	*result;
	char	*strfchr;

	strfchr = NULL;
	if (fd == -1)
		return (0);
	result = ft_calloc(1, sizeof(char));
	if (!result)
		return (0);
	if (!buf)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (0);
	}
	else
	{
		strfchr = ft_strfchr(buf, '\n');
		if (strfchr)
		{
			buf = ft_strchr(buf, '\n') + 1;
			return (strfchr);
		}
		result = ft_strjoin(result, buf);
	}
	i = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0 && !strfchr) {
		printf("BUF: %s\n", buf);
		i = 1;
		strfchr = ft_strfchr(buf, '\n');
		if (!strfchr)
			result = ft_strjoin(result, buf);
		else
			result = ft_strjoin(result, strfchr);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (!i)
		return (0);
	return (result);
	printf("Ret: %d, I: %d, Strfchr: (%s)\n", ret, i, strfchr);
	return (0);
}
