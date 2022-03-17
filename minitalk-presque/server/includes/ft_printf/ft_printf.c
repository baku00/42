/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:01:08 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 18:49:31 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdarg.h>

static int	ft_check_char(char c, va_list args)
{
	int		c_counter;

	if (c == 'c')
		c_counter = ft_print_c(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		c_counter = ft_print_d(va_arg(args, int));
	else if (c == 'p')
		c_counter = ft_print_p(va_arg(args, unsigned long int));
	else if (c == 's')
		c_counter = ft_print_s(va_arg(args, char *));
	else if (c == 'u')
		c_counter = ft_print_u(va_arg(args, unsigned int));
	else if (c == 'x')
		c_counter = ft_print_x(va_arg(args, int), 0);
	else if (c == 'X')
		c_counter = ft_print_x(va_arg(args, int), 1);
	else if (c == '%')
		c_counter = ft_print_c('%');
	else
		c_counter = -1;
	va_end(args);
	return (c_counter);
}

int	printf(const char *s, ...)
{
	int			i;
	int			c_counter;
	va_list		args;
	int			result;

	va_start(args, s);
	i = -1;
	c_counter = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			result = ft_check_char(s[++i], args);
			if (result < 0)
				return (-1);
			c_counter += result;
		}
		else
			c_counter += ft_print_c(s[i]);
	}
	va_end(args);
	return (c_counter);
}
