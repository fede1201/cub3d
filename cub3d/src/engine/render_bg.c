#include "../../include/cub3d.h"

static void	fill_line_u32(uint32_t *line, uint32_t color, int width)
{
	int	x;

	x = 0;
	while (x < width)
	{
		line[x] = color;
		x++;
	}
}

static void	draw_half(t_game *g, int start, int end, uint32_t color)
{
	int			y;
	uint32_t	*line;

	y = start;
	while (y < end)
	{
		line = (uint32_t *)(g->render.addr + y * g->render.line_len);
		fill_line_u32(line, color, g->render.screen_w);
		y++;
	}
}

void	draw_background(t_game *g)
{
	int	mid;

	if (!g->render.addr || g->render.bpp != 32)
		return ;
	mid = g->render.screen_h / 2;
	draw_half(g, 0, mid, g->render.ceil_px);
	draw_half(g, mid, g->render.screen_h, g->render.floor_px);
}
