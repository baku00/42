#include "../../../so_long.h"

// static void set_image(t_mlx *mlx, t_map *map, void *image)
// {
//   mlx_put_image_to_window(mlx->mlx, mlx->window, image, map->item_width, map->item_height);
//   map->item_width += map->item_margin_width;
//   if (map->item_width >= map->width)
//   {
//     map->item_width = 0;
//     map->item_height = map->item_margin_height;
//   }
// }
//
// static void fill_line(t_mlx *mlx, t_map *map)
// {
//   int i;
//
//   i = 0;
//   while (map->line[i])
//   {
//     if (map->line[i] == '0')
//       set_image(mlx, map, NULL);
//     else if (map->line[i] == '1')
//       set_image(mlx, map, mlx->wall);
//     else if (map->line[i] == 'C')
//       set_image(mlx, map, mlx->coin);
//     else if (map->line[i] == 'E')
//       set_image(mlx, map, mlx->exit);
//     else if (map->line[i] == 'P')
//       set_image(mlx, map, mlx->player1);
//     i++;
//   }
// }
//
// void fill_map(t_mlx *mlx, t_map *map)
// {
//   map->line = "";
//   while (map->line)
//   {
//     map->line = get_next_line(map->fd);
//     fill_line(mlx, map);
//   }
// }
