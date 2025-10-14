#include "../../include/cub3d.h"

int	zbuffer_create(t_game *g)
{
	if (!g)
		return (1);
	g->zbuf = (double *)malloc(sizeof(double) * g->render.screen_w);
	if (!g->zbuf)
		return (1);
	return (0);
}

void	zbuffer_destroy(t_game *g)
{
	if (g && g->zbuf)
	{
		free(g->zbuf);
		g->zbuf = NULL;
	}
}
