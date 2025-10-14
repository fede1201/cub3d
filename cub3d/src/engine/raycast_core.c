#include "../../include/cub3d.h"

#define INF_DIST 1e30

static double	rc_abs(double v)
{
	if (v < 0.0)
		return (-v);
	return (v);
}

void	rc_ray_init(t_game *g, int x, t_ray *r)
{
	double	w;
	double	cam_x;

	w = (double)g->render.screen_w;
	cam_x = 2.0 * (double)x / w - 1.0;
	r->camera_x = cam_x;
	r->ray_dx = g->player.dir.x + g->player.plane.x * cam_x;
	r->ray_dy = g->player.dir.y + g->player.plane.y * cam_x;
	r->map_x = (int)g->player.pos.x;
	r->map_y = (int)g->player.pos.y;
	if (r->ray_dx == 0.0)
		r->delta_dx = INF_DIST;
	else
		r->delta_dx = rc_abs(1.0 / r->ray_dx);
	if (r->ray_dy == 0.0)
		r->delta_dy = INF_DIST;
	else
		r->delta_dy = rc_abs(1.0 / r->ray_dy);
	r->side = 0;
	r->perp_dist = 0.0;
}

static void	rc_dda_setup_x(t_game *g, t_ray *r)
{
	double	px;

	px = g->player.pos.x;
	if (r->ray_dx < 0.0)
	{
		r->step_x = -1;
		r->side_dx = (px - (double)r->map_x) * r->delta_dx;
	}
	else
	{
		r->step_x = 1;
		r->side_dx = ((double)r->map_x + 1.0 - px) * r->delta_dx;
	}
}

static void	rc_dda_setup_y(t_game *g, t_ray *r)
{
	double	py;

	py = g->player.pos.y;
	if (r->ray_dy < 0.0)
	{
		r->step_y = -1;
		r->side_dy = (py - (double)r->map_y) * r->delta_dy;
	}
	else
	{
		r->step_y = 1;
		r->side_dy = ((double)r->map_y + 1.0 - py) * r->delta_dy;
	}
}

void	rc_dda_setup(t_game *g, t_ray *r)
{
	rc_dda_setup_x(g, r);
	rc_dda_setup_y(g, r);
}

static int	rc_is_wall(t_game *g, int mx, int my)
{
	if (my < 0 || my >= g->map.height)
		return (1);
	if (mx < 0 || mx >= g->map.width)
		return (1);
	return (g->map.grid[my][mx] == '1');
}

static void	rc_dda_step(t_ray *r)
{
	if (r->side_dx < r->side_dy)
	{
		r->side_dx += r->delta_dx;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->side_dy += r->delta_dy;
		r->map_y += r->step_y;
		r->side = 1;
	}
}

void	rc_dda_run(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		rc_dda_step(r);
		if (rc_is_wall(g, r->map_x, r->map_y))
			hit = 1;
	}
	if (r->side == 0)
		r->perp_dist = (r->side_dx - r->delta_dx);
	else
		r->perp_dist = (r->side_dy - r->delta_dy);
}
