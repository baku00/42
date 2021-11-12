/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:33 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/12 16:36:27 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_return(int i, char *result)
{
	if (i == 0)
		return (0);
	return (result);
}

static char	*ft_return_ret(char *result)
{
	if (result)
		free(result);
	return (0);
}

static char	*ft_join(char *result, char buf[2])
{
	char	*temp;

	temp = ft_strjoin(result, buf);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}

static void	ft_init(int *i, char buf[2])
{
	buf[1] = '\0';
	i = 0;
}

char	*get_next_line(int fd)
{
	int		i;
	int		ret;
	char	buf[2];
	char	*result;

	result = NULL;
	ft_init(&i, buf);
	ret = read(fd, buf, 1);
	while (ret)
	{
		if (ret == -1)
			return (ft_return_ret(result));
		if (!result)
		{
			result = ft_calloc(1, sizeof(char));
			if (!result)
				return (0);
		}
		result = ft_join(result, buf);
		i++;
		if (buf[0] == '\n')
			break ;
		ret = read(fd, buf, 1);
	}
	return (ft_return(i, result));
}
