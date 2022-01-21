/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:53:41 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 18:46:43 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"
#include <stdio.h>

int	ft_print_d(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_intlen(n));
}
