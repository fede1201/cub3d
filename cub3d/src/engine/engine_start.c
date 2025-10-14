
#include "../../include/cub3d.h"

void start_engine(t_game *g){
   g->mlx = mlx_init();
   g->win = mlx_new_window(g->mlx, g->render.screen_w, g->render.screen_h, "cub3D");
    if (!g->win)
        PRINT_ERR(ERR_WINDOW);

    mlx_loop(g->mlx);
}