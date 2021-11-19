/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:35 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 18:23:30 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include <stdio.h>

int	ft_print_s(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return ((int) ft_strlen(s));
}
