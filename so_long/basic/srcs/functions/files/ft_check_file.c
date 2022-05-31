/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:50 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/01 01:12:23 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

static void	load_map(t_mlx *mlx)
{
	mlx->file.content = ft_strdup("");
	if (!mlx->file.content)
		ft_exit(mlx, "Une erreur de memoire est survenue", 1);
	ft_putstr_fd("Récupération de la ligne 1\n", 1);
	mlx->file.line = get_next_line(mlx->file.fd);
	if (!mlx->file.line)
		ft_exit(mlx, "Une erreur de memoire est survenue", 1);
	mlx->file.width = ft_strlen(mlx->file.line);
	while (mlx->file.line && ft_strncmp(mlx->file.line, "\n", 1))
	{
		ft_putstr_fd("Copie du contenu\n", 1);
		mlx->file.content = ft_strjoin(mlx->file.content, mlx->file.line);
		ft_putstr_fd("Récupération de la ligne ", 1);
		ft_putnbr_fd(mlx->file.height + 2, 1);
		ft_putstr_fd("\n", 1);
		mlx->file.line = get_next_line(mlx->file.fd);
		if (mlx->file.line && mlx->file.width != ft_strlen(mlx->file.line))
			ft_exit(mlx, ERROR_FILE_WIDTH, 1);
		mlx->file.height++;
	}
	ft_putstr_fd("Vérification de la taille de la map\n", 1);
	if (mlx->file.width == mlx->file.height)
		ft_exit(mlx, ERROR_FILE_SIZE, 1);
	mlx->file.content_length = ft_strlen(mlx->file.content);
}

static void	create_mapper(t_mlx *mlx)
{
	size_t	y;

	y = 0;
	ft_putstr_fd("Création de la map virtuel\n", 1);
	mlx->file.point = ft_calloc(mlx->file.height, sizeof(int *));
	if (!mlx->file.point)
		ft_exit(mlx, "Une erreur de memoire est survenue", 1);
	while (y < mlx->file.height)
	{
		mlx->file.point[y] = ft_calloc(mlx->file.width, sizeof(int));
		if (!mlx->file.point[y])
			ft_exit(mlx, "Une erreur de memoire est survenue", 1);
		y++;
	}
}

static void	save_map(t_mlx *mlx)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	ft_putstr_fd("Sauvegarde de la map\n", 1);
	while (i < mlx->file.content_length && y < mlx->file.height)
	{
		if (mlx->file.content[i] == '\n')
		{
			i++;
			y++;
			x = 0;
			continue ;
		}
		mlx->file.point[y][x] = mlx->file.content[i];
		if (!valid_char(mlx, y, x))
			ft_exit(mlx, ERROR_BAD_CHAR, 1);
		x++;
		i++;
	}
	check_limit(mlx);
}

static void	check_map(t_mlx *mlx)
{
	size_t	i;

	i = -1;
	while (++i < mlx->file.width - 1)
		if (mlx->file.point[0][i] != '1' || \
		mlx->file.point[mlx->file.height - 1][i] != '1')
			ft_exit(mlx, ERROR_MAP_WALL, 1);
	i = -1;
	while (++i < mlx->file.height)
		if (mlx->file.point[i][0] != '1' || \
		mlx->file.point[i][mlx->file.width - 2] != '1')
			ft_exit(mlx, ERROR_MAP_WALL, 1);
}

void	ft_check_file(t_mlx *mlx, char *filename)
{
	ft_putstr_fd("Vérification du nom de la map\n", 1);
	if (ft_strncmp((filename + ft_strlen(filename)) - 4, ".ber", 4))
		ft_exit(mlx, ERROR_FILENAME, 1);
	mlx->file.name = ft_strdup(filename);
	if (!mlx->file.name)
		ft_exit(mlx, "Une erreur de memoire est survenue", 1);
	ft_putstr_fd("Ouverture du fichier\n", 1);
	mlx->file.fd = open(filename, O_RDONLY);
	if (mlx->file.fd <= 0)
		ft_exit(mlx, ERROR_OPEN, 1);
	ft_putstr_fd("Sauvegarde du nom du fichier\n", 1);
	load_map(mlx);
	create_mapper(mlx);
	save_map(mlx);
	check_map(mlx);
}
