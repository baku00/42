/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:48 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:36:49 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "../header_bonus.h"

typedef struct s_window
{
	int		height;
	int		width;
	char	*title;
	void	*ptr;
}	t_window;
#endif
