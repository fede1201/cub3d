#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
    t_game g;

	init_check(&g, argc, argv);
    debug_fill_game(&g);
    start_engine(&g);


	return (0);
}
