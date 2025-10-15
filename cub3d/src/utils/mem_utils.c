#include "../include/cub3d.h"

bool ft_strisnum(char *str)
{
    int x;

    x = 0;
    while(str[x])
    {
        if(!(str[x] >= '0' && str[x] <= '9'))
            return (false);
        x++;
    }
    return (true);
}