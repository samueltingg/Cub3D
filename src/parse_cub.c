/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:48:19 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 11:45:23 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will extract the lines from the .cub file and
// pass them to parse_line.
void	parse_cub_file(char *map_file, t_map *map)
{
	bool	map_detected;
	int		fd;
	char	*line;

	map_detected = false;
	if (!check_file_extension(map_file))
		err_and_exit(EXTENSION_ERR);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		err_and_exit(FILE_OPEN_ERR);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, map, &map_detected);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_completeness(map), 1)
		err_and_exit(INCOMPLETE_DATA_ERR);
	close(fd);
}

// This function will parse the line and call the relevant function
// depending on the data type to be stored.
void	parse_line(char *line, t_map *map, bool *map_detected)
{
	char	*s;

	s = line;
	skip_characters(WHITESPACE, &s);
	if (!*s && !(*map_detected))
		return ;
	else if (!(ft_strncmp(s, "NO", 2) && ft_strncmp(s, "SO", 2)
			&& ft_strncmp(s, "WE", 2) && ft_strncmp(s, "EA", 2)))
		parse_texture(s, map);
	else if (*s == 'F' || *s == 'C')
		parse_color(s, map);
	else if (detect_map(line) || *map_detected)
		parse_map(line, map);
}

// This function will store the texture paths in their corresponding fields.
void	parse_texture(char *s, t_map *map)
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
	if (!ft_strncmp(id, "NO", 2) && !map->north_texture)
		map->north_texture = trimmed_path;
	else if (!ft_strncmp(id, "SO", 2) && !map->south_texture)
		map->south_texture = trimmed_path;
	else if (!ft_strncmp(id, "WE", 2) && !map->west_texture)
		map->west_texture = trimmed_path;
	else if (!ft_strncmp(id, "EA", 2) && !map->east_texture)
		map->east_texture = trimmed_path;
}

// This function will store the floor and ceiling colors in their
// corresponding fields.
void	parse_color(char *s, t_map *map)
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
	if (id == 'F' && map->floor_color < 0)
		map->floor_color = color_int;
	else if (id == 'C' && map->ceiling_color < 0)
		map->ceiling_color = color_int;
}
