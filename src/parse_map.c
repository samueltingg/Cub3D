/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:48:19 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 17:29:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function initializes the map data structure.
t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		err_and_exit(MAP_MALLOC_ERR);
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->grid = NULL;
	return (map);
}

// This function will extract the lines from the map file and
// pass them to parse_line.
void	parse_map(char *map_file, t_map *map)
{
	int		fd;
	char	*line;

	if (!check_file_extension(map_file))
		err_and_exit(EXTENSION_ERR);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		err_and_exit(FILE_OPEN_ERR);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// This function checks that the filename ends with the .cub extension.
bool	check_file_extension(const char *filename)
{
	const char	*extension = ".cub";
	size_t		len_filename;
	size_t		len_extension;

	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	return (len_filename > len_extension
		&& ft_strncmp(filename + (len_filename - len_extension),
			extension, len_extension) == 0);
}

// This function will parse the line and call the relevant function
// depending on the data type to be stored.
void	parse_line(char *line, t_map *map)
{
	char	*s;

	s = line;
	skip_characters(WHITESPACE, &s);
	if (!*s)
		return ;
	else if (!(ft_strncmp(s, "NO", 2) && ft_strncmp(s, "SO", 2)
			&& ft_strncmp(s, "WE", 2) && ft_strncmp(s, "EA", 2)))
		store_texture(s, map);
	// else if (*s == 'F' || *s == 'C')
	// 	store_color(s, map);
}

// This function will store the texture paths in their corresponding fields.
void	store_texture(char *s, t_map *map)
{
	char	*id;
	char	*path_start;
	int		len;
	char	*trimmed_path;

	id = s;
	s += 2;
	skip_characters(WHITESPACE, &s);
	path_start = s;
	while (*s)
		s++;
	len = s - path_start;
	if (len <= 0)
		err_and_exit(TEXTURE_PATH_ERR);
	trimmed_path = ft_strtrim(ft_substr(path_start, 0, len), WHITESPACE);
	if (!ft_strncmp(id, "NO", 2))
		map->north_texture = trimmed_path;
	else if (!ft_strncmp(id, "SO", 2))
		map->south_texture = trimmed_path;
	else if (!ft_strncmp(id, "WE", 2))
		map->west_texture = trimmed_path;
	else if (!ft_strncmp(id, "EA", 2))
		map->east_texture = trimmed_path;
}

// // This function will store the floor and ceiling colors in their corresponding fields.
// void	store_color(char *s, t_map *map)
// {
// 	char	id;
// 	char	*color_start;
// 	int		len;

// 	id = s;
// 	s += 1;
// 	skip_characters(WHITESPACE, &s);
// 	color_start = s;
// 	while (*s)
// 		s++;
// 	len = s - color_start;
// 	if (len <= 0)
// 		err_and_exit(COLOR_ERR);
// 	color_to_integer(ft_substr(color_start, 0, len));


// 	if (id == 'F')
// 		map->floor_color = ;
// 	else if (id == 'C')
// 		map->ceiling_color = ;



// }

// color_to_integer(char *color_str)
// {
// 	int		R;
// 	int		G;
// 	int		B;

// }
