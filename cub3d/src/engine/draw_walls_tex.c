#include "../../include/cub3d.h"

static int	tex_x_from_wallx(t_game *g, t_rayhit *h)
{
	int	tx;
	int	w;

	w = g->assets.tex_w[h->slice.face];
	tx = (int)(h->slice.wall_x * (double)w);
	if (h->ray.side == 0 && h->ray.ray_dx > 0.0)
		tx = w - tx - 1;
	if (h->ray.side == 1 && h->ray.ray_dy < 0.0)
		tx = w - tx - 1;
	return (tx);
}

static int	clamp_ty(int ty, int max_h)
{
	if (ty < 0)
		return (0);
	if (ty >= max_h)
		return (max_h - 1);
	return (ty);
}

static void	put_pixel(t_game *g, int x, int y, char *src)
{
	char	*dst;

	dst = g->render.addr + y * g->render.line_len
		+ x * (g->render.bpp / 8);
	*(uint32_t *)dst = *(uint32_t *)src;
}

static char	*get_tex_pixel(t_game *g, t_rayhit *h, int tx, int ty)
{
	char	*src;

	src = g->assets.tex_addr[h->slice.face]
		+ ty * g->assets.line_len[h->slice.face]
		+ tx * (g->assets.bpp[h->slice.face] / 8);
	return (src);
}

static void	draw_slice_tex(t_game *g, int x, t_rayhit *h)
{
	int		y;
	int		tx;
	int		ty;
	double	step;
	double	tpos;

	tx = tex_x_from_wallx(g, h);
	step = (double)g->assets.tex_h[h->slice.face] / (double)h->slice.line_h;
	tpos = (h->slice.draw_start - g->render.screen_h / 2
			+ h->slice.line_h / 2) * step;
	y = h->slice.draw_start;
	while (y <= h->slice.draw_end)
	{
		ty = (int)tpos;
		ty = clamp_ty(ty, g->assets.tex_h[h->slice.face]);
		put_pixel(g, x, y, get_tex_pixel(g, h, tx, ty));
		tpos += step;
		y++;
	}
}

void	draw_walls_tex(t_game *g)
{
	int			x;
	t_rayhit	h;

	x = 0;
	while (x < g->render.screen_w)
	{
		rc_cast_column(g, x, &h);
		draw_slice_tex(g, x, &h);
		x++;
	}
}
