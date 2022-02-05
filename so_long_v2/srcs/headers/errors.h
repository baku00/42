#ifndef ERRORS_H
# define ERRORS_H
# include "../header.h"
# define ERROR_SYNTAXE "./so_long <map>"
# define ERROR_FILENAME "La map doit-être un '.ber'"
# define ERROR_OPEN "Une erreur est survenu lors de l'ouverture du fichier"
# define ERROR_FILE_WIDTH "Erreur au niveau de la largeur \
	de la map (Vérification la longueur des lignes)"
# define ERROR_FILE_SIZE "La largeur et la longueur sont identique"
# define ERROR_TO_MANY_PLAYER "Il ne peut y avoir qu'il seul joueur"
# define ERROR_NOT_ENOUGH_PLAYER "Il manque un joueur"
# define ERROR_TO_MANY_WALL "Il y a trop de mur"
# define ERROR_NOT_ENOUGH_WALL "Il n'y a pas assez de mur"
# define ERROR_TO_MANY_COLLECTIBLE "Il y a trop d'objet à récupérer"
# define ERROR_NOT_ENOUGH_COLLECTIBLE "Il n'y a pas assez d'objet à récupérer"
# define ERROR_TO_MANY_EXIT "Il y a trop de sortie"
# define ERROR_NOT_ENOUGH_EXIT "Il n'y a pas assez de sortie"
# define ERROR_MAP_WALL "La map n'est pas fermée"
#endif
