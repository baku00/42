/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../so_long.h"

t_message	init_message(void)
{
	t_message	message;

	message.win = "Vous avez gagné";
	message.movement = "Deplacement: ";
	return (message);
}
