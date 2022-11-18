/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:13:22 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:01:59 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char	nbr[12];
	int		i;

	i = 0;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb == -2147483648)
	{
		nbr[i] = '8';
		nb = nb / 10;
		i++;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	while (nb != 0)
	{
		nbr[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (--i >= 0)
		write(fd, &nbr[i], 1);
}
