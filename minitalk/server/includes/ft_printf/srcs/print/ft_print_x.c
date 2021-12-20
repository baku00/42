/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:51:55 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 17:52:09 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_x(unsigned int n, int maj)
{
	char	*itob;
	int		len;

	itob = ft_itob(n, HEXA, maj);
	len = ft_strlen(itob);
	ft_putstr_fd(itob, 1);
	free(itob);
	return (len);
}
