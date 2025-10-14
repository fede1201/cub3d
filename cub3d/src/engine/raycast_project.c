#include "../../include/cub3d.h"

static double	rc_mod1(double v)
{
	double	i;

	i = floor(v);
	return (v - i);
}

static int	rc_pick_face(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dx > 0.0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (r->ray_dy > 0.0)
		return (TEX_NO);
	return (TEX_SO);
}

static void	rc_calc_draw_range(t_game *g, t_slice *s)
{
	int	h;

	h = g->render.screen_h;
	s->draw_start = -s->line_h / 2 + h / 2;
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end = s->line_h / 2 + h / 2;
	if (s->draw_end >= h)
		s->draw_end = h - 1;
}

void	rc_project(t_game *g, t_ray *r, t_slice *s)
{
	int		h;
	double	ws;

	h = g->render.screen_h;
	s->line_h = (int)(h / (r->perp_dist + 1e-9));
	rc_calc_draw_range(g, s);
	if (r->side == 0)
		ws = g->player.pos.y + r->perp_dist * r->ray_dy;
	else
		ws = g->player.pos.x + r->perp_dist * r->ray_dx;
	s->wall_x = rc_mod1(ws);
	s->face = rc_pick_face(r);
}
