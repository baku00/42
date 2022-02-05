#include "so_long.h"

static void	create_instance(t_mlx *mlx)
{
	t_elements		elements;
	t_collectible	collectible;
	t_exit			exit;
	t_player		player;
	t_wall			wall;

	collectible.count = 0;
	collectible.total_count = 0;
	exit.is_enabled = 0;
	exit.count = 0;
	wall.count = 0;
	player.x = 0;
	player.y = 0;
	player.movement = 0;
	player.count = 0;
	elements.collectible = collectible;
	elements.exit = exit;
	elements.wall = wall;
	elements.player = player;
	mlx->elements = elements;
}

int	main(int argc, char **argv){
	t_mlx	mlx;

	if (argc != 2)
		ft_exit(ERROR_SYNTAXE, 1);
	create_instance(&mlx);
	printf("Analyse du fichier\n");
	ft_check_file(&mlx, argv[1]);
	printf("Création de la map\n");
	ft_create_map(&mlx);
	printf("Placement des images\n");
	set_images(&mlx);
	mlx_key_hook(mlx.window.ptr, key_hook, &mlx);
	mlx_hook(mlx.window.ptr, 17, 1L << 17, mlx_close, &mlx);
	printf("\n\n\nDébut du jeu\n");
	mlx_loop(mlx.ptr);
	return (0);
}
