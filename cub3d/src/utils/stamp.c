#include "../include/cub3d.h"

void print_vec2(t_vec2 v)
{
    printf("x: %f, y: %f\n", v.x, v.y);
}

void print_rgb(t_rgb c)
{
    printf("r: %d, g: %d, b: %d\n", c.r, c.g, c.b);
}

void print_textures(t_textures t)
{
    printf("Textures:\n");
    printf("  NO: %s\n", t.no ? t.no : "(null)");
    printf("  SO: %s\n", t.so ? t.so : "(null)");
    printf("  WE: %s\n", t.we ? t.we : "(null)");
    printf("  EA: %s\n", t.ea ? t.ea : "(null)");
}

void print_colors(t_colors c)
{
    printf("Colors:\n");
    printf("  Floor -> ");
    print_rgb(c.floor_rgb);
    printf("  Ceil  -> ");
    print_rgb(c.ceil_rgb);
}

void print_map(t_map m)
{
    printf("Map:\n");
    printf("  Width: %d, Height: %d\n", m.width, m.height);
    printf("  Spawn: (%d, %d, dir=%c)\n", m.spawn_x, m.spawn_y, m.spawn_dir);
    if (m.grid)
    {
        printf("  Grid:\n");
        for (int y = 0; y < m.height; y++)
            printf("    %s\n", m.grid[y]);
    }
    else
        printf("  Grid: (null)\n");
}

void print_player(t_player p)
{
    printf("Player:\n");
    printf("  Position -> "); print_vec2(p.pos);
    printf("  Direction -> "); print_vec2(p.dir);
    printf("  Plane -> "); print_vec2(p.plane);
    printf("  Move speed: %f\n", p.move_speed);
    printf("  Rot speed: %f\n", p.rot_speed);
}

void print_render(t_render r)
{
    printf("Render:\n");
    printf("  img: %p, addr: %p\n", r.img, r.addr);
    printf("  bpp: %d, line_len: %d, endian: %d\n", r.bpp, r.line_len, r.endian);
    printf("  screen_w: %d, screen_h: %d\n", r.screen_w, r.screen_h);
    printf("  ceil_px: %u, floor_px: %u\n", r.ceil_px, r.floor_px);
}

void print_assets(t_assets a)
{
    printf("Assets:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("  Texture %d:\n", i);
        printf("    tex_img: %p\n", a.tex_img[i]);
        printf("    tex_addr: %p\n", a.tex_addr[i]);
        printf("    tex_w: %d, tex_h: %d\n", a.tex_w[i], a.tex_h[i]);
        printf("    bpp: %d, line_len: %d, endian: %d\n",
               a.bpp[i], a.line_len[i], a.endian[i]);
    }
}

void print_game(t_game *g)
{
    printf("=== GAME STRUCT ===\n");
    print_textures(g->textures);
    print_colors(g->colors);
    print_map(g->map);
    print_player(g->player);
    print_render(g->render);
    print_assets(g->assets);

    printf("mlx: %p, win: %p\n", g->mlx, g->win);

    printf("Header OK: %d, Map OK: %d\n", g->header_ok, g->map_ok);

    printf("Keys:\n");
    for (int i = 0; i < KEY_MAX; i++)
    {
        if (g->keys[i])
            printf("  Key[%d] = %d\n", i, g->keys[i]);
    }

    printf("File:\n");
    if (g->file)
    {
        for (int i = 0; g->file[i]; i++)
            printf("  %s\n", g->file[i]);
    }
    else
        printf("  (null)\n");

    printf("Z-buffer: %p\n", g->zbuf);
    printf("===================\n");
}
