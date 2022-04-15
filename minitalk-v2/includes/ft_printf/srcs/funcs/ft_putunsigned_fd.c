/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:54:13 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 17:54:14 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include <unistd.h>

void	ft_putunsigned_fd(unsigned long long int nb, int fd)
{
	char	nbr[20];
	int		i;

	i = 0;
	if (nb == 0)
		write(fd, "0", 1);
	while (nb != 0)
	{
		nbr[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (--i >= 0)
		write(fd, &nbr[i], 1);
}
