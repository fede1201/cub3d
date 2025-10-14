#ifndef CUB3D_H
#define CUB3D_H

#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "error_handler.h"
#include "struct_cub_3d.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

//utils



//init_check
void    check_args(int argc, char *argv[]);

//parsing


//debug
void debug_fill_game(t_game *g);

//engine

void start_engine(t_game *g);
#endif