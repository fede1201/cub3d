#include "../../include/cub3d.h"

int	render_frame(t_game *g)
{
	if (!g || !g->mlx || !g->win)
		return (0);
	if (!g->render.img || !g->render.addr)
		return (0);
	if (g->render.bpp != 32)
		PRINT_ERR(ERR_IMAGE_ADDR);
	handle_input(g);
	draw_background(g);
	draw_walls_tex(g);
	mlx_put_image_to_window(g->mlx, g->win, g->render.img, 0, 0);
	return (0);
}
