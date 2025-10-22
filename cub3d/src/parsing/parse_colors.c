<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taras <taras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:00:00 by taras             #+#    #+#             */
/*   Updated: 2025/10/10 18:00:00 by taras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Libera un array di stringhe allocato da ft_split */
static void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/* Controlla che una stringa contenga solo cifre */
static int	ft_is_numeric_str(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* Conta quanti elementi contiene un array di stringhe */
static int	ft_strarr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

/* Parsing e validazione di un colore RGB */
static int	validate_and_set_color(char *value, t_rgb *rgb)
{
	char	**p;

	p = ft_split(value, ',');
	if (!p || ft_strarr_len(p) != 3)
		return (ft_free_split(p),
			print_err("Error\nColor format must be R,G,B\n"));
	if (!ft_is_numeric_str(p[0]) || !ft_is_numeric_str(p[1])
		|| !ft_is_numeric_str(p[2]))
		return (ft_free_split(p),
			print_err("Error\nColor values must be digits\n"));
	rgb->r = ft_atoi(p[0]);
	rgb->g = ft_atoi(p[1]);
	rgb->b = ft_atoi(p[2]);
	ft_free_split(p);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255
		|| rgb->b < 0 || rgb->b > 255)
		return (print_err("Error\nColor out of range [0-255]\n"));
	return (0);
}

/* Analizza e salva le direttive NO/SO/WE/EA/F/C */
static int	process_directive(char *line, t_game *g)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (g->textures.no ? print_err("Error\nDuplicate NO\n") :
			(g->textures.no = ft_strtrim(line + 3, " \n")), 0);
	if (!ft_strncmp(line, "SO ", 3))
		return (g->textures.so ? print_err("Error\nDuplicate SO\n") :
			(g->textures.so = ft_strtrim(line + 3, " \n")), 0);
	if (!ft_strncmp(line, "WE ", 3))
		return (g->textures.we ? print_err("Error\nDuplicate WE\n") :
			(g->textures.we = ft_strtrim(line + 3, " \n")), 0);
	if (!ft_strncmp(line, "EA ", 3))
		return (g->textures.ea ? print_err("Error\nDuplicate EA\n") :
			(g->textures.ea = ft_strtrim(line + 3, " \n")), 0);
	if (!ft_strncmp(line, "F ", 2))
		return (g->colors.floor_rgb.r != -1 ?
			print_err("Error\nDuplicate Floor\n") :
			validate_and_set_color(line + 2, &g->colors.floor_rgb));
	if (!ft_strncmp(line, "C ", 2))
		return (g->colors.ceil_rgb.r != -1 ?
			print_err("Error\nDuplicate Ceiling\n") :
			validate_and_set_color(line + 2, &g->colors.ceil_rgb));
	return (print_err("Error\nInvalid directive\n"));
}

/* Legge le 6 direttive e ritorna l'indice d'inizio mappa */
int	parse_header(char **lines, t_game *g)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (lines[i])
	{
		if (ft_is_empty_line(lines[i]))
			i++;
		else if (!process_directive(lines[i], g))
		{
			count++;
			i++;
		}
		else
			return (-1);
		if (count == 6)
			break ;
	}
	if (count < 6)
		return (print_err("Error\nMissing directives\n"), -1);
	return (i);
}
=======
#include "../include/cub3d.h"

int	parse_floor_color(t_game *g, char **file)
{
	int	ret;

	ret = parse_color_id_in_file(&g->colors.floor_rgb, file, 'F');
	if (ret == 1)
		return (1);
	if (ret == -1)
		PRINT_ERR(ERR_DUP_ID);
	else
		PRINT_ERR(ERR_MISS_ID);
	return (0);
}

int	parse_ceiling_color(t_game *g, char **file)
{
	int	ret;

	ret = parse_color_id_in_file(&g->colors.ceil_rgb, file, 'C');
	if (ret == 1)
		return (1);
	if (ret == -1)
		PRINT_ERR(ERR_DUP_ID);
	else
		PRINT_ERR(ERR_MISS_ID);
	return (0);
}
>>>>>>> ca270282ea8b3b33211fa53ddfec719ddfeb1edb
