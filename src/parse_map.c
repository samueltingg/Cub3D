/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:48:19 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 20:09:36 by etien            ###   ########.fr       */
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
	else if (*s == 'F' || *s == 'C')
		store_color(s, map);
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
	trimmed_path = ft_strtrim_mod(ft_substr(path_start, 0, len), WHITESPACE);
	if (!ft_strncmp(id, "NO", 2))
		map->north_texture = trimmed_path;
	else if (!ft_strncmp(id, "SO", 2))
		map->south_texture = trimmed_path;
	else if (!ft_strncmp(id, "WE", 2))
		map->west_texture = trimmed_path;
	else if (!ft_strncmp(id, "EA", 2))
		map->east_texture = trimmed_path;
}

// This function will store the floor and ceiling colors in their corresponding fields.
void	store_color(char *s, t_map *map)
{
	char	id;
	char	*color_start;
	int		len;
	char	*trimmed_color;
	int		color_int;

	id = *s;
	s += 1;
	skip_characters(WHITESPACE, &s);
	color_start = s;
	while (*s)
		s++;
	len = s - color_start;
	if (len <= 0)
		err_and_exit(COLOR_ERR);
	trimmed_color = ft_strtrim_mod(ft_substr(color_start, 0, len), WHITESPACE);
	color_str_to_int(trimmed_color, &color_int);
	free(trimmed_color);
	if (id == 'F')
		map->floor_color = color_int;
	else if (id == 'C')
		map->ceiling_color = color_int;
}

// This function will convert the color string to its integer representation.
void	color_str_to_int(char *color_str, int *color_int)
{
	char	**color_arr;
	int		R;
	int		G;
	int		B;

	color_arr = ft_split(color_str, ',');
	if (!check_color_format(color_arr))
		err_and_exit(COLOR_ERR);
	R = ft_atoi(color_arr[0]);
	G = ft_atoi(color_arr[1]);
	B = ft_atoi(color_arr[2]);
	*color_int = (R << 16) | (G << 8) | B;
	free_double_arr(color_arr);
}

// This function checks that the color has been correctly formatted:
// - composed of three values
// - each value has a maximum of three digits
//   (additional check to avoid integer overflow)
// - each value must be between 0 and 255
bool	check_color_format(char **color_arr)
{
	int		i;

	i = 0;
	while (color_arr[i])
		i++;
	if (i != 3)
		return (false);
	i = 0;
	while (color_arr[i])
	{
		color_arr[i] = ft_strtrim_mod(color_arr[i], WHITESPACE);
		if (ft_strlen(color_arr[i]) > 3
			|| ft_atoi(color_arr[i]) < 0
			|| ft_atoi(color_arr[i]) > 255)
			return (false);
		i++;
	}
	return (true);
}
