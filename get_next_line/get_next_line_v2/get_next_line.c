/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:33 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/17 14:18:33 by dgloriod         ###   ########.fr       */
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
	int	ret;
	static char	*buf;
	char	*result;
	char	*strfchr;
	char	*temp;

	if (fd == -1)
		return (0);
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (0);
	if (!buf || !buf[0])
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
		{
			free(result);
			return (0);
		}
	}
	else
	{
		strfchr = ft_strfchr(buf, '\n');
		if (strfchr)
		{
			free(result);
			if (ft_strlen(buf) == ft_strlen(strfchr))
				free(buf);
			else
			{
				result = ft_strdup(buf);
				free(buf);
				buf = ft_strdup(ft_strchr(result, '\n') + 1);
				free(result);
			}
			return (strfchr);
		}
		return (buf);
	}
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0 && !strfchr) {
		strfchr = ft_strfchr(buf, '\n');
		if (strfchr)
		{
			temp = ft_strjoin(result, strfchr);
			free(strfchr);
			strfchr = ft_strdup(buf);
			buf = ft_strdup(ft_strchr(strfchr, '\n'));
			free(strfchr);
			return (temp);
		}
		else
			result = ft_strjoin(result, buf);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ret == -1)
	{
		if (buf)
			free(buf);
		if ()
		return (0);
	}
}
