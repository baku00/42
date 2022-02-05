#include "../../so_long.h"

static void	put_images(t_mlx *mlx)
{
	int	x;
	int	y;
	void	*img;

	y = 0;
	while (y < mlx->file.height) {
		x = 0;
		while (x < mlx->file.width - 1) {
			img = mlx->elements.empty.img;
			if (mlx->file.point[y][x] == COLLECTIBLE)
				img = mlx->elements.collectible.img;
			else if (mlx->file.point[y][x] == PLAYER)
				img = mlx->elements.player.img;
			else if (mlx->file.point[y][x] == WALL)
				img = mlx->elements.wall.img;
			mlx_put_image_to_window(
				mlx->ptr,
				mlx->window.ptr,
				img,
				x * ITEM_WIDTH,
				y * ITEM_HEIGHT
			);
			x++;
		}
		y++;
	}
}

void	set_images(t_mlx *mlx)
{
	int	width;
	int	height;

	width = ITEM_WIDTH;
	height = ITEM_HEIGHT;
	mlx->elements.collectible.img = mlx_xpm_file_to_image(mlx->ptr, \
		COLLECTIBLE_IMG, \
		&width, \
		&height \
	);
	mlx->elements.exit.img = mlx_xpm_file_to_image(mlx->ptr, \
		EXIT_IMG, \
		&width, \
		&height \
	);
	mlx->elements.empty.img = mlx_xpm_file_to_image(mlx->ptr, \
		EMPTY_IMG, \
		&width, \
		&height \
	);
	mlx->elements.player.img = mlx_xpm_file_to_image(mlx->ptr, \
		PLAYER_IMG, \
		&width, \
		&height \
	);
	mlx->elements.wall.img = mlx_xpm_file_to_image(mlx->ptr, \
		WALL_IMG, \
		&width, \
		&height \
	);
	printf("Placement\n");
	put_images(mlx);
}
