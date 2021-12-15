/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

char	*get_point(char *point, int x, int y)
{
	char	*cx;
	char	*cy;

	cx = ft_itoa(x);
	cy = ft_itoa(y);
	if (ft_strlen(point))
		point = ft_strjoin(point, ",");
	point = ft_strjoin(point, "x:");
	point = ft_strjoin(point, cx);
	point = ft_strjoin(point, ";y:");
	point = ft_strjoin(point, cy);
	free(cx);
	free(cy);
	return (point);
}
