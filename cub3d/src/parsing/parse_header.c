#include "../../include/cub3d.h"

static int valid_map(char **s)
{
	int	i;
	int	y;

	i = 0;
	while(s[i][y])
	{
		y = 0;
		while (s[i][y])
		{
			if (s[i])
		
		}
		
	}
	
	while (s[i])
	{
		y = 0;
		while (s[i][y])
		{
			if (s[i][y] != ' ' && s[i][y] != '0' && s[i][y] != '1' &&
			s[i][y] != 'N' && s[i][y] != 'S' && s[i][y] != 'E' &&
			s[i][y] != 'W' && s[i][y] != '\n')
				return (0);
			//devo continuare
		}
	}
}
