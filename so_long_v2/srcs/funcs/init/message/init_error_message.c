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

t_error_message	init_error_message()
{
	t_error_message	error_message;

	error_message.wrong_count_argument = "Merci de préciser une map";
	error_message.wrong_map_width = "La largeur de la map n'est pas correct";
	error_message.wrong_map_size = "La taille de la map n'est pas correct (La largeur est égal à la hauteur)";
	error_message.line_error = "";
	error_message.line_number_error = 0;
	error_message.wrong_map_format = "Le format de la map est incorrect (Format requis: rectangulaire)";
	error_message.wrong_map_close = "La map n'est pas fermée";
	error_message.wrong_char_map = "La map contient des caractères non valide";
	error_message.invalid_char = ft_calloc(1, sizeof(char));
	return (error_message);
}
