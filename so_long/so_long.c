#include "mlx/mlx.h"
#include "so_long.h"

int main(int argc, char **argv)
{
  t_map map;

  map.accepted_chars[0] = EMPTY;
  map.accepted_chars[1] = WALL;
  map.accepted_chars[2] = COLLECTIBLE;
  map.accepted_chars[3] = EXIT;
  map.accepted_chars[4] = START_PLAYER_POSITION;
  map.accepted_chars[5] = '\0';
  map.char_to_string[1] = '\0';
  if (argc != 2 || !valid_map(argv[1], map))
    error();
  t_mlx mlx;
  mlx.mlx = mlx_init();
  mlx.height = 1000;
  mlx.width = 1000;
  int img_h = 10;
  int img_w = 10;
  mlx.window = mlx_new_window(mlx.mlx, mlx.height, mlx.width, "SO_LONG");
  mlx.coin = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/coin.xpm", &img_h, &img_w);
  mlx.exit = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/exit.xpm", &img_h, &img_w);
  mlx.player1 = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/player1.xpm", &img_h, &img_w);
  mlx.wall = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/wall.xpm", &img_h, &img_w);
  mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.coin, 10, 10);
  mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.exit, 30, 30);
  mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.player1, 50, 50);
  mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.wall, 70, 70);
  mlx_loop(mlx.mlx);
  return 0;
}
//gcc mlx/libmlx.a main.c -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx
