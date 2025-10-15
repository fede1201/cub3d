#include "../include/cub3d.h"

static int ends_with(const char *s, const char *suffix)
{
	size_t ls;
	size_t lf;

    ls = ft_strlen(s);
	lf = ft_strlen(suffix);
	if (ls < lf) //da controllare se va bene solo il < o serve il <=
        return 0;
	return (ft_strncmp(s + (ls - lf), suffix, lf) == 0); //devo chiedere all'ing
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		PRINT_ERR(ERR_BAD_ARGS);
	if (!ends_with(argv[1], ".cub"))
		PRINT_ERR(ERR_BAD_EXT);
}
