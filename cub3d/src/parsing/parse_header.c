#include "../include/cub3d.h"

static int	parse_rgb(char *str, t_rgb *color)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		return (print_err("Error\nInvalid RGB format\n"), ft_free_split(split), 1);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	ft_free_split(split);
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (print_err("Error\nRGB value out of range\n"), 1);
	return (0);
}

int	parse_header(char **lines, t_game *game)
{
	int	i;

	i = 0;
	while (lines[i] && i < 6)
	{
		if (!ft_strncmp(lines[i], "NO ", 3))
			game->textures.no = ft_strtrim(lines[i] + 3, " \n");
		else if (!ft_strncmp(lines[i], "SO ", 3))
			game->textures.so = ft_strtrim(lines[i] + 3, " \n");
		else if (!ft_strncmp(lines[i], "WE ", 3))
			game->textures.we = ft_strtrim(lines[i] + 3, " \n");
		else if (!ft_strncmp(lines[i], "EA ", 3))
			game->textures.ea = ft_strtrim(lines[i] + 3, " \n");
		else if (!ft_strncmp(lines[i], "F ", 2))
			parse_rgb(lines[i] + 2, &game->colors.floor_rgb);
		else if (!ft_strncmp(lines[i], "C ", 2))
			parse_rgb(lines[i] + 2, &game->colors.ceil_rgb);
		else
			break ;
		i++;
	}
	return (i);
}
