#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_game t_game;

typedef enum e_tex {
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3
}	t_tex;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dx;
	double	ray_dy;
	int		map_x;
	int		map_y;
	double	side_dx;
	double	side_dy;
	double	delta_dx;
	double	delta_dy;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_dist;
}	t_ray;

typedef struct s_slice
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		face;
}	t_slice;

typedef struct s_rayhit
{
	t_ray	ray;
	t_slice	slice;
}	t_rayhit;

int	rc_cast_column(t_game *g, int x, t_rayhit *out);
void	rc_ray_init(t_game *g, int x, t_ray *r);
void	rc_dda_setup(t_game *g, t_ray *r);
void	rc_dda_run(t_game *g, t_ray *r);
void	rc_project(t_game *g, t_ray *r, t_slice *s);

#endif
