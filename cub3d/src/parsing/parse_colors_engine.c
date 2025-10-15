#include "../include/cub3d.h"

static int	parse_component(char *raw, int *out)
{
	char	*trim;
	int		val;

	if (!raw)
		return (0);
	trim = ft_strtrim(raw, " \t\r\n");
	if (!trim)
		return (0);
	if (!is_pure_num(trim))
		return (free(trim), 0);
	val = ft_atoi(trim);
	free(trim);
	if (val < 0 || val > 255)
		return (0);
	*out = val;
	return (1);
}

static int	parse_rgb_triplet(const char *payload, int *r, int *g, int *b)
{
	char	**m;
	int		ok;

	if (!payload)
		return (0);
	m = ft_split(payload, ',');
	if (!m)
		return (0);
	if (!m[0] || !m[1] || !m[2] || m[3])
		return (free_split(m), 0);
	ok = parse_component(m[0], r)
		&& parse_component(m[1], g)
		&& parse_component(m[2], b);
	free_split(m);
	return (ok);
}

static const char	*skip_ws(const char *s)
{
	while (*s && (unsigned char)*s <= 32)
		s++;
	return (s);
}

static int	save_color_generic(t_rgb *dst, const char *line, char id)
{
	const char	*p;
	char		*payload;
	int			r;
	int			g;
	int			b;

	if (!line)
		return (0);
	p = skip_ws(line);
	if (*p != id)
		return (0);
	p++;
	p = skip_ws(p);
	payload = ft_strtrim(p, " \t\r\n");
	if (!payload)
		return (0);
	if (!parse_rgb_triplet(payload, &r, &g, &b))
		return (free(payload), 0);
	free(payload);
	dst->r = r;
	dst->g = g;
	dst->b = b;
	return (1);
}
int	parse_color_id_in_file(t_rgb *dst, char **file, char id)
{
	int		x;
	int		found;

	x = 0;
	found = 0;
	while (file && file[x])
	{
		if (save_color_generic(dst, file[x], id))
		{
			if (found)
				return (-1);
			found = 1;
		}
		x++;
	}
	return (found ? 1 : 0);
}
