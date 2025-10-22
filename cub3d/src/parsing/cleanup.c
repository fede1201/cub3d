
#include "../include/cub3d.h"

static void free_map_grid(t_map *m) 
    
{ 
    
 int i; 
    
 
    
 if (!m->grid) 
    
 return ; 
    
 i = 0; 
    
 while (m->grid[i]) 
    
 free(m->grid[i++]); 
    
 free(m->grid); 
    
 m->grid = NULL; 
    
} 
    
 
    
void free_all(t_game *g) 
    
{ 
    
 if (!g) 
    
 return ; 
    
 if (g-> 
    textures.no) 
    
 free(g-> 
    textures.no); 
    
 if (g->textures.so) 
    
 free(g->textures.so); 
    
 if (g->textures.we) 
    
 free(g->textures.we); 
    
 if (g->textures.ea) 
    
 free(g->textures.ea); 
    
 free_map_grid(&g->map); 
    
 if (g->zbuf) 
    
 free(g->zbuf); 
    
 g->zbuf = NULL; 
    
} 