#include "../../include/cub3d.h"
#include <math.h>

static void	apply_move(t_game *g, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = g->player.pos.x + dx;
	ny = g->player.pos.y + dy;
	if (can_walk(g, nx, g->player.pos.y))
		g->player.pos.x = nx;
	if (can_walk(g, g->player.pos.x, ny))
		g->player.pos.y = ny;
}

static void	apply_rotation(t_game *g, double ang)
{
	double	old_dx;
	double	old_px;

	old_dx = g->player.dir.x;
	old_px = g->player.plane.x;
	g->player.dir.x = g->player.dir.x * cos(ang)
		- g->player.dir.y * sin(ang);
	g->player.dir.y = old_dx * sin(ang) + g->player.dir.y * cos(ang);
	g->player.plane.x = g->player.plane.x * cos(ang)
		- g->player.plane.y * sin(ang);
	g->player.plane.y = old_px * sin(ang) + g->player.plane.y * cos(ang);
}

static void	handle_movement(t_game *g, double ms)
{
	if (g->keys[KEY_W])
		apply_move(g, g->player.dir.x * ms, g->player.dir.y * ms);
	if (g->keys[KEY_S])
		apply_move(g, -g->player.dir.x * ms, -g->player.dir.y * ms);
	if (g->keys[KEY_A])
		apply_move(g, -g->player.plane.x * ms, -g->player.plane.y * ms);
	if (g->keys[KEY_D])
		apply_move(g, g->player.plane.x * ms, g->player.plane.y * ms);
}

static void	handle_rotation(t_game *g, double rs)
{
	if (g->keys[KEY_LEFT])
		apply_rotation(g, -rs);
	if (g->keys[KEY_RIGHT])
		apply_rotation(g, rs);
}

void	handle_input(t_game *g)
{
	double	ms;
	double	rs;

	if (!g)
		return ;
	ms = g->player.move_speed;
	rs = g->player.rot_speed;
	handle_movement(g, ms);
	handle_rotation(g, rs);
}
