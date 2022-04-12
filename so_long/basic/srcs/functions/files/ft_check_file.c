/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:33:50 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/12 03:27:07 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

static void	load_map(t_mlx *mlx)
{
	printf("Récupération de la ligne 1\n");
	mlx->file.line = get_next_line(mlx->file.fd);
	mlx->file.content = ft_strdup("");
	if (!mlx->file.content)
		ft_exit(mlx, "Une erreur de memoire est survenue", 1);
	mlx->file.height = 0;
	if (!mlx->file.line)
		ft_exit(mlx, "Une erreur de memoire est survenue", 1);
	mlx->file.width = ft_strlen(mlx->file.line);
	while (mlx->file.line && ft_strncmp(mlx->file.line, "\n", 1))
	{
		printf("Copie du contenu\n");
		mlx->file.content = ft_strjoin(mlx->file.content, mlx->file.line);
		printf("Récupération de la ligne %ld\n", mlx->file.height + 2);
		mlx->file.line = get_next_line(mlx->file.fd);
		if (mlx->file.line && mlx->file.width != ft_strlen(mlx->file.line))
			ft_exit(mlx, ERROR_FILE_WIDTH, 1);
		mlx->file.height++;
	}
	printf("Vérification de la taille de la map\n");
	if (mlx->file.width == mlx->file.height)
		ft_exit(mlx, ERROR_FILE_SIZE, 1);
	mlx->file.content_length = ft_strlen(mlx->file.content);
}

static void	create_mapper(t_mlx *mlx)
{
	size_t	y;

	y = 0;
	printf("Création de la map virtuel\n");
	mlx->file.point = ft_calloc(mlx->file.height, sizeof(int *));
	if (!mlx->file.point)
		return ;
	while (y < mlx->file.height)
	{
		mlx->file.point[y] = ft_calloc(mlx->file.width, sizeof(int));
		if (!mlx->file.point[y])
		{
			while (--y > 0)
				free(mlx->file.point[y]);
			free(mlx->file.point[0]);
			free(mlx->file.point);
			return ;
		}
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
	printf("Sauvegarde de la map\n");
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
		check_char(mlx, y, x);
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
	t_file	file;

	file.content = NULL;
	file.line = NULL;
	file.width = 0;
	file.height = 0;
	file.point = 0;
	file.content_length = 0;
	file.fd = 0;
	file.name = NULL;
	mlx->file = file;
	printf("Vérification du nom de la map\n");
	if (ft_strncmp((filename + ft_strlen(filename)) - 4, ".ber", 4))
		ft_exit(mlx, ERROR_FILENAME, 1);
	printf("Ouverture du fichier\n");
	mlx->file.fd = open(filename, O_RDONLY);
	if (mlx->file.fd <= 0)
		ft_exit(mlx, ERROR_OPEN, 1);
	printf("Sauvegarde du nom du fichier\n");
	mlx->file.name = ft_strdup(filename);
	load_map(mlx);
	create_mapper(mlx);
	save_map(mlx);
	check_map(mlx);
}
