#include "../../include/cub3d.h"

static int	is_wall(t_game *g, int mx, int my)
{
	if (my < 0 || my >= g->map.height)
		return (1);
	if (mx < 0 || mx >= g->map.width)
		return (1);
	return (g->map.grid[my][mx] == '1');
}

int	can_walk(t_game *g, double nx, double ny)
{
	int	cell_x;
	int	cell_y;

	cell_x = (int)nx;
	cell_y = (int)ny;
	if (is_wall(g, cell_x, cell_y))
		return (0);
	return (1);
}
