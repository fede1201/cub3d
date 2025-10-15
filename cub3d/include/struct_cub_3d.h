#ifndef STRUCT_CUB_3D_H
#define STRUCT_CUB_3D_H

# define KEY_MAX 256

typedef struct s_vec2
{
    double x;
    double y;
} t_vec2;

typedef struct s_rgb
{
    int r;
    int g;
    int b;
} t_rgb;

typedef struct s_textures
{
    char *no;
    char *so;
    char *we;
    char *ea;
} t_textures;

typedef struct s_colors
{
    t_rgb floor_rgb;
    t_rgb ceil_rgb;
} t_colors;

typedef struct s_map
{
    char **grid;
    int width;
    int height;
    int spawn_x;
    int spawn_y;
    char spawn_dir;
} t_map;

typedef struct s_player
{
    t_vec2 pos;
    t_vec2 dir;
    t_vec2 plane;
    double move_speed;
    double rot_speed;
} t_player;

typedef struct s_render
{
    void     *img;
    char     *addr;
    int       bpp;
    int       line_len;
    int       endian;
    int       screen_w;
    int       screen_h;
    uint32_t  ceil_px;
    uint32_t  floor_px;
} t_render;

typedef struct s_assets
{
    void    *tex_img[4];
    char    *tex_addr[4];
    int      tex_w[4];
    int      tex_h[4];
    int      bpp[4];
    int      line_len[4];
    int      endian[4];
} t_assets;

typedef struct s_game
{
    t_textures  textures;
    t_colors    colors;
    t_map       map;
    t_player    player;
    t_render    render;
    t_assets    assets;
    void       *mlx;
    void       *win;
    char       **file;
    double     *zbuf;
    int         keys[KEY_MAX];
    int         header_ok;
    int         map_ok;
} t_game;

#endif