/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:51:40 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:52:05 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error_message	errors(void)
{
	t_error_message	error_message;

	error_message.wrong_wall_number = \
	"Nombre de mur incorrect (Voir ./config/elements/limits.h -> MAX_WALL_COUNT et MIN_WALL_COUNT)";
	error_message.wrong_empty_number = \
	"Nombre de case vide incorrect (Voir ./config/elements/limits.h -> MAX_EMPTY_COUNT et MIN_EMPTY_COUNT)";
	error_message.wrong_exit_number = \
	"Nombre de sortie incorrect (Voir ./config/elements/limits.h -> MAX_EXIT_COUNT et MIN_EXIT_COUNT)";
	error_message.wrong_player_number = \
	"Nombre de joueur incorrect (Voir ./config/elements/limits.h -> MAX_PLAYER_COUNT et MIN_PLAYER_COUNT)";
	error_message.wrong_coin_number = \
	"Nombre de joueur incorrect (Voir ./config/elements/limits.h -> MAX_COIN_COUNT et MIN_COIN_COUNT)";
	error_message.wrong_filename = \
	"Nom de la map incorrect (Doit se terminer par \".ber\")";
	error_message.wrong_count_argument = \
	"Merci de préciser une map";
	error_message.wrong_map_width = \
	"La largeur de la map n'est pas correct";
	error_message.wrong_map_size = \
	"La taille de la map n'est pas correct (La largeur est égal à la hauteur)";
	error_message.line_error = \
	"";
	error_message.line_number_error = \
	0;
	error_message.wrong_map_format = \
	"Le format de la map est incorrect (Format requis: rectangulaire)";
	error_message.wrong_map_close = \
	"La map n'est pas fermée";
	error_message.wrong_char_map = \
	"La map contient des caractères non valide";
	error_message.missing_char = \
	"Des caractères sont manquant";
	return (error_message);
}
