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
bool        ft_strisnum(char *str);
void        free_split(char **m);
int         is_pure_num(const char *s);


//init_check
void	    init_check(t_game *g, int argc, char **argv);
void        check_args(int argc, char *argv[]);
void	check_open_and_valid(const char *path);

//read lines
char        **read_all_lines(char *path);

//parsing
int         parse_color_id_in_file(t_rgb *dst, char **file, char id);

//debug
void        debug_fill_game(t_game *g);

//engine
void	    start_engine(t_game *g);
void	    init_color_bg(t_game *g);
void	    strcut_fill_bg(t_game *g);
void	    draw_background(t_game *g);
void	    create_framebuffer(t_game *g);
int		    render_frame(t_game *g);
int		    load_textures(t_game *g);
void	    draw_walls_tex(t_game *g);
void	    destroy_framebuffer(t_game *g);
void	    zbuffer_destroy(t_game *g);
void	    cleanup_game(t_game *g);
int		    hook_close(t_game *g);
int         hook_key_press(int key, t_game *g);
int         hook_key_release(int key, t_game *g);
int         hook_close(t_game *g);
void        hooks_init(t_game *g);
void        handle_input(t_game *g);
int         can_walk(t_game *g, double nx, double ny);
void        cleanup_game(t_game *g);
int         zbuffer_create(t_game *g);
void        zbuffer_destroy(t_game *g);


// utils stamp
void print_game(t_game *g);

/* read_map.c */
char    **read_all_lines(char *path);

/* parse_cub_file.c */
int     parse_cub_file(char *path, t_game *game);

/* parse_header.c */
int     parse_header(char **lines, t_game *game);

/* parse_map.c */
int     parse_map(char **lines, t_map *map);
int     validate_map(t_map *map);

/* init_struct.c */
void    init_game_struct(t_game *game);

// int     validate_map(t_map *m);

// /* utils_parsing.c */
// void    free_lines(char **lines);
void    ft_free_split(char **arr);
int     ft_is_empty_line(char *s);

// /* errors.c */
// int     print_err(char *msg);

// /* cleanup.c */
// void    free_all(t_game *g

void init_player(t_player *p, t_map *m);


#endif