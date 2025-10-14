#include "../../include/cub3d.h"

static void	init_texture_paths(char **path, t_game *g)
{
	path[0] = g->textures.no;
	path[1] = g->textures.so;
	path[2] = g->textures.we;
	path[3] = g->textures.ea;
}

static int	load_single_texture(t_game *g, char *path, int i)
{
	g->assets.tex_img[i] = mlx_xpm_file_to_image(g->mlx, path,
			&g->assets.tex_w[i], &g->assets.tex_h[i]);
	if (!g->assets.tex_img[i])
		return (1);
	g->assets.tex_addr[i] = mlx_get_data_addr(g->assets.tex_img[i],
			&g->assets.bpp[i], &g->assets.line_len[i],
			&g->assets.endian[i]);
	if (!g->assets.tex_addr[i] || g->assets.bpp[i] != 32)
		return (1);
	return (0);
}

int	load_textures(t_game *g)
{
	char	*path[4];
	int		i;

	init_texture_paths(path, g);
	i = 0;
	while (i < 4)
	{
		if (load_single_texture(g, path[i], i))
			PRINT_ERR(ERR_TEXTURE_LOAD);
		i++;
	}
	return (0);
}
