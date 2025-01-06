/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:48:19 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 16:00:54 by etien            ###   ########.fr       */
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

// This function will parse the line and call the relevant function
// depending on the data type to be stored.
void	parse_line(char *line, t_map *map)
{
	char	*s;

	s = line;
	while (*s && ft_strchr(WHITESPACE, *s))
		s++;
	if (!*s || !ft_strcmp(s, "\n"))
		return ;
	if (!(ft_strncmp(s, "NO", 2) && ft_strncmp(s, "SO", 2)
			&& ft_strncmp(s, "WE", 2) && ft_strncmp(s, "EA", 2)))
		store_texture(s, map);
}

// This function will store the texture paths in their corresponding fields.
void	store_texture(char *s, t_map *map)
{
	char	*direction;
	char	*path_start;
	int		len;

	direction = s;
	s += 2;
	while (ft_strchr(WHITESPACE, *s))
		s++;
	path_start = s;
	while (*s && !ft_strchr(" \t\n", *s))
		s++;
	len = s - path_start;
	if (len <= 0)
		err_and_exit(TEXTURE_PATH_ERR);
	if (!ft_strncmp(direction, "NO", 2))
		map->north_texture = ft_substr(path_start, 0, len);
	else if (!ft_strncmp(direction, "SO", 2))
		map->south_texture = ft_substr(path_start, 0, len);
	else if (!ft_strncmp(direction, "WE", 2))
		map->west_texture = ft_substr(path_start, 0, len);
	else if (!ft_strncmp(direction, "EA", 2))
		map->east_texture = ft_substr(path_start, 0, len);
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
