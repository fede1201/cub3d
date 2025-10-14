#include "../../include/cub3d.h"

int	hook_key_press(int key, t_game *g)
{
	if (!g)
		return (0);
	if (key == KEY_ESC)
		return (hook_close(g));
	if (key >= 0 && key < KEY_MAX && !g->keys[key])
		g->keys[key] = 1;
	return (0);
}

int	hook_key_release(int key, t_game *g)
{
	if (!g)
		return (0);
	if (key >= 0 && key < KEY_MAX && g->keys[key])
		g->keys[key] = 0;
	return (0);
}

int	hook_close(t_game *g)
{
	cleanup_game(g);
	exit(0);
	return (0);
}

void	hooks_init(t_game *g)
{
	if (!g || !g->win)
		return ;
	mlx_hook(g->win, 2, 1L << 0, hook_key_press, g);
	mlx_hook(g->win, 3, 1L << 1, hook_key_release, g);
	mlx_hook(g->win, 17, 0, hook_close, g);
}
