/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:54:36 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 17:59:47 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"
#include <stdio.h>

static char	ft_convert(int rest, int maj)
{
	if (maj)
		maj = 32;
	if (rest < 10)
		return (rest + 48);
	return (rest + (87 - maj));
}

static char	*ft_reverse(char *resultat)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(resultat) - 1;
	while (i < j)
	{
		temp = resultat[i];
		resultat[i] = resultat[j];
		resultat[j] = temp;
		i++;
		j--;
	}
	return (resultat);
}

char	*ft_itob(unsigned long int n, int base, int maj)
{
	char	*resultat;
	long	quotient;
	int		rest;
	char	c_rest[2];

	c_rest[1] = '\0';
	resultat = ft_calloc(1, sizeof(char));
	if (!resultat)
		return (0);
	if (n == 0)
		return (ft_strjoin(resultat, "0"));
	while (n > 0)
	{
		quotient = n / base;
		rest = n - (quotient * base);
		c_rest[0] = ft_convert(rest, maj);
		resultat = ft_strjoin(resultat, c_rest);
		n = quotient;
	}
	resultat = ft_reverse(resultat);
	return (resultat);
}
