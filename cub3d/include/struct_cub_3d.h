#ifndef STRUCT_CUB_3D_H
#define STRUCT_CUB_3D_H

/* Tipi base utili */
typedef struct s_vec2   { double x, y; }              t_vec2;
typedef struct s_rgb    { int r, g, b; }              t_rgb;

/* 1) Header */
typedef struct s_textures {
    char *no;   // path
    char *so;
    char *we;
    char *ea;
    /* opzionale: popolati dopo il load MLX
       void *no_img; void *so_img; void *we_img; void *ea_img;
       int no_w, no_h; // dimensioni texture caricate
    */
} t_textures;

typedef struct s_colors {
    t_rgb floor_rgb;   // F
    t_rgb ceil_rgb;    // C
} t_colors;

/* 2) Mappa */
typedef struct s_map {
    char  **grid;      // righe "as-is" normalizzate a rettangolo
    int     width;     // max len riga (spazi compresi)
    int     height;    // numero righe
    int     spawn_x;   // cella di spawn
    int     spawn_y;
    char    spawn_dir; // 'N','S','E','W'
} t_map;

/* 3) Giocatore (stato runtime) */
typedef struct s_player {
    t_vec2 pos;        // in coordinate mappa (double)
    t_vec2 dir;        // direzione vista (unit)
    t_vec2 plane;      // piano camera (per FOV)
    double move_speed; // tuning
    double rot_speed;  // tuning
} t_player;

/* 4) Rendering (runtime) */
typedef struct s_render {
    int     screen_w;  // es. 1024
    int     screen_h;  // es. 768
    void   *img;       // image buffer MLX corrente
    char   *addr;      // data ptr della img
    int     bpp;
    int     line_len;
    int     endian;
} t_render;

/* 5) Assets (immagini caricate) — opzionale separarle dai path */
typedef struct s_assets {
    void *tex_img[4];  // 0:NO,1:SO,2:WE,3:EA
    int   tex_w[4];
    int   tex_h[4];
    // Se vuoi, anche addr/bpp/line_len per ogni texture
} t_assets;

/* 6) Contenitore globale */
typedef struct s_game {
    /* Input/parsing */
    t_textures  textures;   // paths dall’header
    t_colors    colors;
    t_map       map;

    /* Runtime */
    t_player    player;
    t_render    render;
    t_assets    assets;

    /* MLX */
    void       *mlx;
    void       *win;

    /* Stato/flags utili */
    int header_ok;   // 1 quando NO/SO/WE/EA/F/C sono validi
    int map_ok;      // 1 quando la mappa ha passato tutte le validazioni
} t_game;

#endif