#include "../../include/cub3d.h"

void	create_framebuffer(t_game *g)
{
	g->render.img = mlx_new_image(g->mlx, g->render.screen_w,
			g->render.screen_h);
	if (!g->render.img)
		PRINT_ERR(ERR_IMAGE);
	g->render.addr = mlx_get_data_addr(g->render.img, &g->render.bpp,
			&g->render.line_len, &g->render.endian);
	if (!g->render.addr)
		PRINT_ERR(ERR_IMAGE_ADDR);
}

void	destroy_framebuffer(t_game *g)
{
	if (g->render.img)
	{
		mlx_destroy_image(g->mlx, g->render.img);
		g->render.img = NULL;
	}
}
