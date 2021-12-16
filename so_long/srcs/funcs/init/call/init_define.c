#include "../../../../so_long.h"

t_define	init_define()
{
	t_define define;

	define.empty = '0';
	define.wall = '1';
	define.coin = 'C';
	define.exit = 'E';
	define.start_player_position = 'P';
	return (define);
}
