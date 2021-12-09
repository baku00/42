#include "mlx/mlx.h"
#include <stdio.h>

int main()
{
  void *mlx;
  void *window;
  mlx = mlx_init();
  int h = 1000;
  int w = 1000;
  window = mlx_new_window(mlx, h * 2, w * 2, "SO_LONG");
  // int wall[19][19] =
  // {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,0,0,10000,10000,0,0,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,0,10000,20000,20000,10000,0,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,10000,20000,30000,30000,20000,10000,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,10000,20000,30000,40000,40000,30000,20000,10000,0,0,0,0,0,0},
  // {0,0,0,0,0,10000,20000,30000,40000,50000,50000,40000,30000,20000,10000,0,0,0,0,0},
  // {0,0,0,0,10000,20000,30000,40000,50000,60000,60000,50000,40000,30000,20000,10000,0,0,0,0},
  // {0,0,0,10000,20000,30000,40000,50000,60000,70000,70000,60000,50000,40000,30000,20000,10000,0,0,0},
  // {0,0,10000,20000,30000,40000,50000,60000,70000,80000,80000,70000,60000,50000,40000,30000,20000,10000,0,0},
  // {0,10000,20000,30000,40000,50000,60000,70000,80000,90000,90000,80000,70000,60000,50000,40000,30000,20000,10000,0},
  // {0,0,10000,20000,30000,40000,50000,60000,70000,80000,80000,70000,60000,50000,40000,30000,20000,10000,0,0},
  // {0,0,0,10000,20000,30000,40000,50000,60000,70000,70000,60000,50000,40000,30000,20000,10000,0,0,0},
  // {0,0,0,0,10000,20000,30000,40000,50000,60000,60000,50000,40000,30000,20000,10000,0,0,0,0},
  // {0,0,0,0,0,10000,20000,30000,40000,50000,50000,40000,30000,20000,10000,0,0,0,0,0},
  // {0,0,0,0,0,0,10000,20000,30000,40000,40000,30000,20000,10000,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,10000,20000,30000,30000,20000,10000,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,0,10000,20000,20000,10000,0,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,0,0,10000,10000,0,0,0,0,0,0,0,0,0},
  // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  // int color = 10000;
  // for (int x = 0; x < 19; x++)
  //   for (int y = 10; y < 29; y++)
  //     mlx_put_image_to_window(mlx, window, x, y, wall[x][y - 10]);
  //mlx_string_put(mlx, window, 0, 10, 20000, "Hello");

  void *image = mlx_xpm_file_to_image(mlx, "./srcs/img/potion3.png", &w, &h);
  //printf("%s\n", );
  //mlx_put_image_to_window(mlx, window, image, 500, 500);
  mlx_png_file_to_image(mlx, "./srcs/img/potion3.png", &w, &h);
  /*int pixel_bits;
  int line_bytes;
  int endian;
  char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
  int color = 0xABCDEF;

  if (pixel_bits != 32)
      color = mlx_get_color_value(mlx, color);

  for(int y = 0; y < 300; ++y)
  for(int x = 0; x < 300; ++x)
  {
      int pixel = (y * line_bytes) + (x * 4);

      if (endian == 1)        // Most significant (Alpha) byte first
      {
          buffer[pixel + 0] = (color >> 24);
          buffer[pixel + 1] = (color >> 16) & 0xFF;
          buffer[pixel + 2] = (color >> 8) & 0xFF;
          buffer[pixel + 3] = (color) & 0xFF;
      }
      else if (endian == 0)   // Least significant (Blue) byte first
      {
          buffer[pixel + 0] = (color) & 0xFF;
          buffer[pixel + 1] = (color >> 8) & 0xFF;
          buffer[pixel + 2] = (color >> 16) & 0xFF;
          buffer[pixel + 3] = (color >> 24);
      }
  }*/

  //mlx_put_image_to_window(mlx, window, image, 1000, 1000);
  //mlx_png_file_to_image(image, "./srcs/img/potion3.png", &w, &h);

  mlx_loop(mlx);
  return 0;
}
//gcc mlx/libmlx.a main.c -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx
