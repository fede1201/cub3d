#include "../include/cub3d.h"

//1Flusso logico corretto

//2Apre il file .cub.

//3Legge tutte le righe.

//4Le memorizza in una lista.

//5Converte la lista in char **lines.

//6Ritorna l’array per il parsing successivo.

static int	count_lines(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	**read_all_lines(char *path)
{
	int		fd;
	char	*line;
	t_list	*lst;
	char	**lines;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_err("Error\nCannot reopen file\n"), NULL);
	lst = NULL;
	while ((line = get_next_line(fd)))
		ft_lstadd_back(&lst, ft_lstnew(line));
	close(fd);
	lines = malloc((count_lines(lst) + 1) * sizeof(char *));
	if (!lines)
		return (ft_lstclear(&lst, free), print_err("Error\nMalloc failed\n"), NULL);
	i = 0;
	while (lst)
	{
		lines[i++] = lst->content;
		lst = lst->next;
	}
	lines[i] = NULL;
	ft_lstclear(&lst, NULL);
	return (lines);
}
