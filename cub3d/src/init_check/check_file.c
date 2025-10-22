#include "../include/cub3d.h"

void	check_open_and_valid(const char *path)
{
	int     fd;
	char    b;
	ssize_t n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		PRINT_ERR(ERR_BAD_FILE);

	n = read(fd, &b, 1);
	if (n == 0)
    {
		close(fd);
		PRINT_ERR(ERR_EMPTY_FILE);
	}
	if (n < 0)
    {
		if (errno == EISDIR)	
        {
			close(fd);
			PRINT_ERR(ERR_IS_DIR);
		}
		close(fd);
		PRINT_ERR(ERR_IO);
	}
	close(fd);
}


