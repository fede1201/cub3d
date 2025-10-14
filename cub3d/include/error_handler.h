#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# define ERR_BAD_ARGS      "Bad ARGS, no map provided"
# define ERR_BAD_EXT       "Invalid extension, map must be '.cub' file"
# define ERR_BAD_FILE      "Cannot open .cub file"
# define ERR_EMPTY_FILE    "File is empty"
# define ERR_IS_DIR        "Path is a directory"
# define ERR_IO            "I/O error while reading file"
# define ERR_BAD_ID        "Unknown identifier"
# define ERR_DUP_ID        "Duplicate identifier"
# define ERR_MISS_ID       "Missing identifier (NO/SO/WE/EA/F/C)"
# define ERR_PATH_EMPTY    "Missing texture path"
# define ERR_PATH_JUNK     "Extra data after texture path"
# define ERR_TEX_OPEN      "Cannot open texture file"
# define ERR_CLR_FMT       "Invalid color format (R,G,B expected)"
# define ERR_CLR_RANGE     "Color value out of range [0-255]"
# define ERR_CLR_DUP       "Duplicate color entry"
# define ERR_HDR_JUNK      "Unexpected content in header"
# define ERR_HDR_INCOMP    "Header incomplete before map"
# define ERR_MAP_NOTLAST   "Map is not last section"
# define ERR_MAP_EMPTY     "Map is empty"
# define ERR_MAP_CHAR      "Invalid character in map"
# define ERR_SPAWN_NONE    "No player spawn found"
# define ERR_SPAWN_MULTI   "Multiple player spawns found"
# define ERR_MAP_OPEN      "Map not closed by walls"
# define ERR_MAP_HOLE      "Map leaks into void"
# define ERR_TRAIL_DATA    "Unexpected content after map"
# define ERR_MEM           "Memory allocation failed"
# define ERR_UNKNOWN       "Unknown error"

//___________________________________________________________________

# define ERR_WINDOW			"Window creation failed"

# define PRINT_ERR(msg) \
	do { printf("Error\n%s\n", msg); exit(EXIT_FAILURE); } while (0)

#endif
