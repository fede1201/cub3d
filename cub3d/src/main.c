#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_err("Error\nUsage: ./cub3D <path/to/map.cub>\n"));
	
	// 2. Inizializzazione della struct di gioco (fondamentale)
	// Deve mettere a NULL tutti i puntatori e i valori a -1 o 0.
	init_game_struct(&game); 
	
	// 3. Esegui il parsing (argv[1] è il percorso del file)
	if (parse_cub_file(argv[1], &game))
	{
		// Se il parsing fallisce, pulisci tutto ed esci con codice d'errore.
		// Assumi free_game_resources gestisce la liberazione di textures, grid, ecc.
		//free_game_resources(&game);
		return (1); 
	}
	
	// 4. Se il parsing ha successo, procedi con l'esecuzione del gioco
	// init_mlx(&game);
	// game_loop(&game);
	print_game(&game);
	// 5. Cleanup finale (se il gioco termina normalmente)
	//free_game_resources(&game);

	return (0);
}

// Nota: Dovrai implementare le funzioni init_game_struct e free_game_resources.
