#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Libera tutte le righe e l’array
void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

// Aggiunge una nuova riga all’array esistente
static char	**append_line(char **lines, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (lines && lines[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (free_lines(lines), NULL);
	i = 0;
	while (lines && lines[i])
	{
		new[i] = lines[i];
		i++;
	}
	new[i] = line;
	new[i + 1] = NULL;
	free(lines);
	return (new);
}

// Legge tutte le righe del file e le restituisce come array di stringhe
char	**read_all_lines(char *path)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		lines = append_line(lines, line);
		if (!lines)
			return (close(fd), NULL);
	}
	close(fd);
	return (lines);
}
