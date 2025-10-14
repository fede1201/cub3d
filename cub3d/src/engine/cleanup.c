#include "../../include/cub3d.h"

static void	free_map(t_game *g)
{
	int	y;

	if (!g || !g->map.grid)
		return ;
	y = 0;
	while (y < g->map.height)
	{
		if (g->map.grid[y])
			free(g->map.grid[y]);
		y++;
	}
	free(g->map.grid);
	g->map.grid = NULL;
}

static void	destroy_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g->assets.tex_img[i])
			mlx_destroy_image(g->mlx, g->assets.tex_img[i]);
		i++;
	}
}

void	cleanup_game(t_game *g)
{
	destroy_textures(g);
	destroy_framebuffer(g);
	zbuffer_destroy(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	free_map(g);
}
