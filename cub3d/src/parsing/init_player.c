#include "../include/cub3d.h"

void init_player(t_player *p, t_map *m)
{
char dir;

dir = m->spawn_dir;
p->pos.x = m->spawn_x + 0.5;
p->pos.y = m->spawn_y + 0.5;
if (dir == 'N')
{
p->dir.x = 0;
p->dir.y = -1;
p->plane.x = 0.66;
p->plane.y = 0;
}
else if (dir == 'S')
{
p->dir.x = 0;
p->dir.y = 1;
p->plane.x = -0.66;
p->plane.y = 0;
}
else if (dir == 'E')
{
p->dir.x = 1;
p->dir.y = 0;
p->plane.x = 0;
p->plane.y = 0.66;
}
else if (dir == 'W')
{
p->dir.x = -1;
p->dir.y = 0;
p->plane.x = 0;
p->plane.y = -0.66;
}
p->move_speed = 0.08;
p->rot_speed = 0.05;
}