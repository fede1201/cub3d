#include "../../include/cub3d.h"

static void	init_keys(t_game *g)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
	{
		g->keys[i] = 0;
		i++;
	}
}

void	start_engine(t_game *g)
{
	if (!g)
		PRINT_ERR(ERR_UNKNOWN);
	g->mlx = mlx_init();
	if (!g->mlx)
		PRINT_ERR(ERR_MLX_INIT);
	g->win = mlx_new_window(g->mlx, g->render.screen_w,
			g->render.screen_h, "cub3D");
	if (!g->win)
		PRINT_ERR(ERR_WINDOW);
	create_framebuffer(g);
	if (zbuffer_create(g))
		PRINT_ERR(ERR_ZBUFFER);
	init_color_bg(g);
	load_textures(g);
	init_keys(g);
	hooks_init(g);
	mlx_loop_hook(g->mlx, render_frame, g);
	mlx_loop(g->mlx);
}
