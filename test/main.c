#include "mlx_linux/mlx.h"

int main(int argc, char **argv)
{
	int height = 100;
	int width = 100;
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, height, width, "SO_LONG");
	mlx_loop(mlx);
	return 0;
}
//gcc mlx/libmlx.a main.c -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx
