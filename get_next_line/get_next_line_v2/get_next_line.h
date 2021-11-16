/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:28:52 by dgloriod          #+#    #+#             */
/*   Updated: 2021/11/16 13:47:55 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif