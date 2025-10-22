#include "cub3d.h"



int	parse_map(char **lines, t_map *map)
{
	int	h;
	int	w;
	int	len;

	h = 0;
	while (lines[h] && lines[h][0] != '\0')
		h++;
	map->grid = malloc((h + 1) * sizeof(char *));
	if (!map->grid)
		return (print_err("Error\nMalloc failed\n"));
	w = 0;
	while (w < h)
	{
		len = ft_strlen(lines[w]);
		map->grid[w] = ft_strdup(lines[w]);
		if (!map->grid[w])
			return (print_err("Error\nMalloc failed\n"));
		if (len > map->width)
			map->width = len;
		w++;
	}
	map->grid[w] = NULL;
	map->height = h;
	return (0);
}

static int	check_charset(t_map *m, int *sx, int *sy, char *sd)
{
	int	y;
	int	x;
	int	spawns;

	spawns = 0;
	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (m->grid[y][++x])
		{
			if (!ft_strchr("01NSEW ", m->grid[y][x]))
				return (print_err("Error\nInvalid character in map\n"));
			if (ft_strchr("NSEW", m->grid[y][x]))
			{
				spawns++;
				*sx = x;
				*sy = y;
				*sd = m->grid[y][x];
			}
		}
	}
	if (spawns != 1)
		return (print_err("Error\nInvalid number of spawns\n"));
	return (0);
}

int	validate_map(t_map *m)
{
	int	sx;
	int	sy;
	char	sd;

	if (check_charset(m, &sx, &sy, &sd))
		return (1);
	m->spawn_x = sx;
	m->spawn_y = sy;
	m->spawn_dir = sd;
	return (0);
}
