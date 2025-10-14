#include "../../include/cub3d.h"

static int	clamp_color(int c)
{
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}

uint32_t	rgb_to_u32(int r, int g, int b)
{
	r = clamp_color(r);
	g = clamp_color(g);
	b = clamp_color(b);
	return (((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b);
}

void	init_color_bg(t_game *g)
{
	g->render.ceil_px = rgb_to_u32(g->colors.ceil_rgb.r,
			g->colors.ceil_rgb.g, g->colors.ceil_rgb.b);
	g->render.floor_px = rgb_to_u32(g->colors.floor_rgb.r,
			g->colors.floor_rgb.g, g->colors.floor_rgb.b);
}
