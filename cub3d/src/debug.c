/* DEBUG-ONLY: riempie t_game con dati validi per partire subito con l'engine.
   - Crea una mappa chiusa 10x8 con spawn 'N'.
   - Alloca g->map.grid e sostituisce il carattere di spawn con '0'.
   - Imposta path texture, colori, player, viewport e flag.
   - Nota: i path texture qui sono stringhe letterali -> NON chiamare free() su di esse.
   - La mappa invece è allocata -> libera ogni riga + l'array quando esci. */

#include "cub3d.h"   /* deve contenere t_game, t_vec2, t_rgb, ecc. */
#include <string.h>  /* strlen */
#include <stdlib.h>  /* malloc */

void debug_fill_game(t_game *g)
{
    /* 0) Reset */
    memset(g, 0, sizeof(*g));

    /* 1) Header “come da Persona B” */
    g->textures.no = "/Users/federico2/Desktop/cub3d/cub3d/assets/textures/east.xpm";
    g->textures.so = "/Users/federico2/Desktop/cub3d/cub3d/assets/textures/north.xpm";
    g->textures.we = "/Users/federico2/Desktop/cub3d/cub3d/assets/textures/south.xpm";
    g->textures.ea = "/Users/federico2/Desktop/cub3d/cub3d/assets/textures/west.xpm";

    g->colors.floor_rgb = (t_rgb){120, 80, 40};
    g->colors.ceil_rgb  = (t_rgb){180, 200, 255};

    /* 2) Mappa di test (chiusa), con uno spawn 'N' alla riga 2 colonna 2 (0-based) */
    static const char *raw[] = {
        "111111111111111111111111",
"100000000000000000000001",
"100000000000000000000001",
"100000000N00000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000111110000101010001",
"100000100010000000000001",
"100000100010000100010001",
"100000100010000000000001",
"100000111100001010100001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"111111111000000000000001",
"100100001000000000000001",
"100000101000000000000001",
"100100001000000000000001",
"100111111000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"111111111111111111111111",
        
        
        NULL
    };

    g->map.width  = 24;
    g->map.height = 26;
    g->map.grid   = (char**)malloc(sizeof(char*) * g->map.height);

    int found_spawn = 0;
    for (int y = 0; y < g->map.height; ++y) {
        size_t len = strlen(raw[y]);
        g->map.grid[y] = (char*)malloc(len + 1);
        for (size_t x = 0; x < len; ++x) {
            char c = raw[y][x];
            if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && !found_spawn) {
                g->map.spawn_x  = (int)x;
                g->map.spawn_y  = (int)y;
                g->map.spawn_dir = c;
                g->map.grid[y][x] = '0'; /* normalizzo la cella di spawn a camminabile */
                found_spawn = 1;
            } else {
                g->map.grid[y][x] = c;
            }
        }
        g->map.grid[y][len] = '\0';
    }

    /* 3) Player (coerente con lo spawn) */
    g->player.pos = (t_vec2){ g->map.spawn_x + 0.5, g->map.spawn_y + 0.5 };
    /* Direzione & piano camera (FOV ~66°) */
    switch (g->map.spawn_dir) {
        case 'N': g->player.dir = (t_vec2){ 0.0, -1.0 }; g->player.plane = (t_vec2){ 0.66,  0.0 }; break;
        case 'S': g->player.dir = (t_vec2){ 0.0,  1.0 }; g->player.plane = (t_vec2){-0.66,  0.0 }; break;
        case 'E': g->player.dir = (t_vec2){ 1.0,  0.0 }; g->player.plane = (t_vec2){ 0.0,   0.66}; break;
        case 'W': g->player.dir = (t_vec2){-1.0,  0.0 }; g->player.plane = (t_vec2){ 0.0,  -0.66}; break;
        default:  g->player.dir = (t_vec2){ 0.0, -1.0 }; g->player.plane = (t_vec2){ 0.66,  0.0 }; break; /* fallback */
    }
    g->player.move_speed = 0.06;
    g->player.rot_speed  = 0.04;

    /* 4) Viewport / Render */
    g->render.screen_w = 1024;
    g->render.screen_h = 768;

    /* 5) Flag “tutto validato” */
    g->header_ok = 1;
    g->map_ok    = 1;
}
