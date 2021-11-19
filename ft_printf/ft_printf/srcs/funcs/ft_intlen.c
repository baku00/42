/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:57:05 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 17:58:20 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_intlen(long int nbr)
{
	unsigned long int	n;
	unsigned long int	nb;
	int					l;

	n = 1;
	l = 1;
	nb = nbr;
	if (nbr < 0)
	{
		nb = nbr * -1;
		l++;
	}
	if (nb < 10)
		return (l);
	while (n < nb)
	{
		n *= 10;
		l++;
	}
	if (n > nb)
	{
		n /= 10;
		l--;
	}
	return (l);
}
