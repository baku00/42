/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:00:04 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/18 18:47:12 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef HEXA
#  define HEXA 16
# endif
# ifndef BINARY
#  define BINARY 2
# endif
# include "includes/libft/libft.h"

int		ft_printf(const char *s, ...);
void	ft_putunsigned_fd(unsigned long long int nb, int fd);
char	*ft_itob(unsigned long int n, int base, int maj);
int		ft_intlen(long int nb);
int		ft_print_c(char c);
int		ft_print_d(int n);
int		ft_print_p(unsigned long int p);
int		ft_print_s(char *s);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int n, int maj);
#endif
