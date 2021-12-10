#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef CONST
#  define CONST
#  define SRCS "./srcs"
#  define IMG SRCS"/img"
#  define MAPS SRCS"/maps"
#  define EMPTY 'O'
#  define WALL '1'
#  define COLLECTIBLE 'C'
#  define EXIT 'E'
#  define START_PLAYER_POSITION 'P'
# endif
# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_mlx
{
  void  *mlx;
  void  *window;
  int   height;
  int   width;
  void  *coin;
  void  *exit;
  void  *player1;
  void  *wall;
} t_mlx;

typedef struct  s_map
{
  int width;
  int height;
  int fd;
  char *line;
  int valid_top;
  int valid_bottom;
  int valid_left;
  int valid_right;
  char *previous_line;
  char accepted_chars[6];
  char char_to_string[2];
} t_map;

int main(int argc, char **argv);
int valid_map(char *filename, t_map map);
void error(void);
int valid_shape(char *filename, t_map map);
int is_n_only(const char *str, const char c, const int length);
int is_at(const char *str, const char c, const int i);

#endif
