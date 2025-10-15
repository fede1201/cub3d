#ifndef CUB3D_H
#define CUB3D_H

#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include "error_handler.h"
#include "struct_cub_3d.h"
# include "raycast.h"
# include "keycodes_mac.h" 
# include "../libft/libft.h"
# include "../mlx/mlx.h"

//utils
uint32_t	rgb_to_u32(int r, int g, int b);


//init_check
void	init_check(t_game *g, int argc, char **argv);
void    check_args(int argc, char *argv[]);

//parsing


//debug
void debug_fill_game(t_game *g);

//engine
void	start_engine(t_game *g);
void	init_color_bg(t_game *g);
void	strcut_fill_bg(t_game *g);
void	draw_background(t_game *g);
void	create_framebuffer(t_game *g);
int		render_frame(t_game *g);
int		load_textures(t_game *g);
void	draw_walls_tex(t_game *g);
void	destroy_framebuffer(t_game *g);
void	zbuffer_destroy(t_game *g);
void	cleanup_game(t_game *g);
int		hook_close(t_game *g);
int   hook_key_press(int key, t_game *g);
int   hook_key_release(int key, t_game *g);
int   hook_close(t_game *g);
void  hooks_init(t_game *g);
void  handle_input(t_game *g);
int   can_walk(t_game *g, double nx, double ny);
void  cleanup_game(t_game *g);
int   zbuffer_create(t_game *g);
void  zbuffer_destroy(t_game *g);


#endif