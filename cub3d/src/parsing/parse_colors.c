#include "../include/cub3d.h"

int	parse_floor_color(t_game *g, char **file)
{
	int	ret;

	ret = parse_color_id_in_file(&g->colors.floor_rgb, file, 'F');
	if (ret == 1)
		return (1);
	if (ret == -1)
		PRINT_ERR(ERR_DUP_ID);
	else
		PRINT_ERR(ERR_MISS_ID);
	return (0);
}

int	parse_ceiling_color(t_game *g, char **file)
{
	int	ret;

	ret = parse_color_id_in_file(&g->colors.ceil_rgb, file, 'C');
	if (ret == 1)
		return (1);
	if (ret == -1)
		PRINT_ERR(ERR_DUP_ID);
	else
		PRINT_ERR(ERR_MISS_ID);
	return (0);
}
