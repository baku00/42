/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:06 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:22:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void set_image(t_mlx *mlx, t_map *map, void *image)
{
  mlx_put_image_to_window(mlx->mlx, mlx->window, image, map->item_width, map->item_height);
  map->item_width += map->item_margin_width;
}

static void set_player(t_mlx *mlx, t_map *map)
{
  t_point point;
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->player->img, map->item_width, map->item_height);
  point.x = map->item_width;
  point.y = map->item_height;
  map->item_width += map->item_margin_width;
  mlx->player->point = point;
}

static void fill_line(t_mlx *mlx, t_map *map)
{
  int i;

  i = 0;
  while (map->line[i] != '\n')
  {
    if (map->line[i] == '0')
      set_image(mlx, map, mlx->empty);
    else if (map->line[i] == '1')
    {
      mlx->wall->point.x = map->item_width;
      mlx->wall->point.y = map->item_height;
      mlx->wall->point.point = get_point(mlx->wall->point.point, mlx->wall->point.x, mlx->wall->point.y);
      set_image(mlx, map, mlx->wall->img);
    }
    else if (map->line[i] == 'C')
    {
      mlx->coin->count += 1;
      mlx->coin->point.x = map->item_width;
      mlx->coin->point.y = map->item_height;
      mlx->coin->point.point = get_point(mlx->coin->point.point, mlx->coin->point.x, mlx->coin->point.y);
      set_image(mlx, map, mlx->coin->img);
    }
    else if (map->line[i] == 'E')
    {
      mlx->exit->point.x = map->item_width;
      mlx->exit->point.y = map->item_height;
      set_image(mlx, map, mlx->empty);
    }
    else if (map->line[i] == 'P')
      set_player(mlx, map);
    i++;
  }
  map->item_height += map->item_margin_height;
  map->item_width = 0;
}

static void fill_map(t_mlx *mlx, t_map *map)
{
  map->line = "";
  while (map->line)
  {
    map->line = get_next_line(map->fd);
    if (!map->line)
      break;
    fill_line(mlx, map);
  }
}

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
  if (argc != 2 || !valid_map(argv[1], &map))
    error();
  t_mlx mlx;
  mlx.map = &map;
  t_player player;
  t_point wall_point;
  t_wall wall;
  t_point coin_point;
  t_point coin_taked;
  t_coin coin;
  t_point exit_point;
  t_exit exit;
  map.item_margin_width = 40;
  map.item_margin_height = 40;
  map.item_width = 0;
  map.item_height = 0;
  mlx.mlx = mlx_init();
  mlx.width = (map.width-1) * map.item_margin_width;
  mlx.height = map.height * map.item_margin_height;
  int img_h = 10;
  int img_w = 10;
  mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "SO_LONG");
  coin.count = 0;
  coin.img = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/coin.xpm", &img_h, &img_w);
  coin_point.point = ft_calloc(1, sizeof(char));
  coin_taked.point = ft_calloc(1, sizeof(char));
  coin.point = coin_point;
  coin.coin_taked = coin_taked;

  wall.img = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/wall.xpm", &img_h, &img_w);
  wall_point.point = ft_calloc(1, sizeof(char));
  wall.point = wall_point;

  exit.img = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/exit.xpm", &img_h, &img_w);
  exit.point = exit_point;
  exit.is_enable = 0;
  mlx.exit = &exit;

  player.img = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/player1.xpm", &img_h, &img_w);
  player.move = 0;
  mlx.player = &player;


  mlx.wall = &wall;
  mlx.coin = &coin;
  mlx.empty = mlx_xpm_file_to_image(mlx.mlx, "./srcs/img/empty.xpm", &img_h, &img_w);
  fill_map(&mlx, &map);
  print_move(&mlx);
  mlx_hook(mlx.window, 3, 0, hook, &mlx);
  mlx_loop(mlx.mlx);
  return 0;
}
