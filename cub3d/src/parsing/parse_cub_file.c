#include "../include/cub3d.h"

static int	exit_parse(char **lines, int ret)
{
	free_lines(lines);
	return (ret);
}

int	parse_cub_file(char *path, t_game *game)
{
	char	**lines;
	int		map_start;

	lines = read_all_lines(path);
	if (!lines)
		return (print_err("Error\nCannot read file content\n"));
	map_start = parse_header(lines, game);
	if (map_start < 0)
		return (exit_parse(lines, 1));
	if (parse_map(lines + map_start, &game->map))
		return (exit_parse(lines, 1));
	if (validate_map(&game->map))
		return (exit_parse(lines, 1));
	init_player(&game->player, &game->map);
	game->header_ok = 1;
	game->map_ok = 1;
	return (exit_parse(lines, 0));
}
