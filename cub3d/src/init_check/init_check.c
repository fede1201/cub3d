#include "../include/cub3d.h"

void	init_check(t_game *g, int argc, char **argv)
{
	check_args(argc, argv);
	check_open_and_valid(argv[1]);
	g->file = read_all_lines(argv[1]);
	
}

