/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:51 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 17:53:32 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"
#include <stdio.h>

int	ft_print_p(unsigned long int n)
{
	char	*itob;
	int		len;

	itob = ft_itob(n, HEXA, 0);
	len = ft_strlen(itob) + 2;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(itob, 1);
	free(itob);
	return (len);
}
