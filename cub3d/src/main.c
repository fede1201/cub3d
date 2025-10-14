#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    t_game g;
	//init_check(argc, argv);

    debug_fill_game(&g);
    start_engine(&g);


	return (0);
}
