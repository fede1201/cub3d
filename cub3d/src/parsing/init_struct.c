#include "../include/cub3d.h"

// Max 25 righe
static void	init_player_and_map(t_game *game)
{
	// Inizializza t_map
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.spawn_x = -1;
	game->map.spawn_y = -1;
	game->map.spawn_dir = 0;

	// Inizializza t_player (i valori saranno settati da init_player)
	game->player.pos.x = 0.0;
	game->player.pos.y = 0.0;
	game->player.dir.x = 0.0;
	game->player.dir.y = 0.0;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.0;
	game->player.move_speed = 0.0;
	game->player.rot_speed = 0.0;
}

// Max 25 righe
static void	init_textures_and_colors(t_game *game)
{
	// Inizializza t_textures (puntatori a NULL)
	game->textures.no = NULL;
	game->textures.so = NULL;
	game->textures.we = NULL;
	game->textures.ea = NULL;

	// Inizializza t_colors (usa -1 come flag "non parsato")
	game->colors.floor_rgb.r = -1;
	game->colors.floor_rgb.g = -1;
	game->colors.floor_rgb.b = -1;
	game->colors.ceil_rgb.r = -1;
	game->colors.ceil_rgb.g = -1;
	game->colors.ceil_rgb.b = -1;
	
	// I membri di t_assets verranno inizializzati al caricamento delle texture
}

// Max 25 righe
void	init_game_struct(t_game *game)
{
	// Pulisce l'intera struct per sicurezza (imposta tutto a zero/NULL)
	ft_bzero(game, sizeof(t_game)); // Assumi ft_bzero o memset
	
	// Chiamate di inizializzazione dettagliate
	init_textures_and_colors(game);
	init_player_and_map(game);

	// Inizializza altri membri
	game->mlx = NULL;
	game->win = NULL;
	game->file = NULL;
	game->zbuf = NULL;
	
	// Flag di stato
	game->header_ok = 0;
	game->map_ok = 0;
	
	// Inizializza l'array dei tasti a 0 (tutti non premuti)
	ft_bzero(game->keys, sizeof(int) * KEY_MAX);
}
