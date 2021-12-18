/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:28:52 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/10 18:10:21 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strdup_line(const char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strchr_line(const char *s, int c);
size_t	ft_strlen_line(const char *str);
void	*ft_calloc_line(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_substr_line(char const *s, unsigned int start, size_t len);
#endif
