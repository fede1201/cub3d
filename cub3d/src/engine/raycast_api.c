#include "../../include/cub3d.h"

int	rc_cast_column(t_game *g, int x, t_rayhit *out)
{
	t_ray	r;
	t_slice	s;

	rc_ray_init(g, x, &r);
	rc_dda_setup(g, &r);
	rc_dda_run(g, &r);
	rc_project(g, &r, &s);
	out->ray = r;
	out->slice = s;
	return (0);
}
