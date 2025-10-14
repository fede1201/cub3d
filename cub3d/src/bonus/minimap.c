#include "../../include/cub3d.h"
#include <stdint.h>

static void	put_px(t_game *g, int x, int y, uint32_t c)
{
	char *p;

	if (x < 0 || y < 0 || x >= g->render.screen_w || y >= g->render.screen_h)
		return ;
	p = g->render.addr + y * g->render.line_len + x * (g->render.bpp / 8);
	*(uint32_t *)p = c;
}

void	draw_minimap(t_game *g)
{
	int	scale;
	int	my;
	int	mx;
	int	y;
	int	x;

	scale = 6;
	my = 0;
	while (my < g->map.height)
	{
		mx = 0;
		while (mx < g->map.width)
		{
			y = 0;
			while (y < scale)
			{
				x = 0;
				while (x < scale)
				{
					put_px(g, 8 + mx * scale + x, 8 + my * scale + y,
						(g->map.grid[my][mx] == '1') ? 0x00666666 : 0x00CCCCCC);
					x++;
				}
				y++;
			}
			mx++;
		}
		my++;
	}
	/* player dot */
	y = 8 + (int)(g->player.pos.y * scale);
	x = 8 + (int)(g->player.pos.x * scale);
	put_px(g, x, y, 0x00FF0000);
}
