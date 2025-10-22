#include "../include/cub3d.h"

void	free_split(char **m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}