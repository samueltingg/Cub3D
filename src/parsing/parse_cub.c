/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:48:19 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 17:02:04 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will extract the lines from the .cub file and
// pass them to parse_line.
void	parse_cub(char *map_file, t_data *data)
{
	bool	map_detected;
	int		fd;
	char	*line;
	t_list	*tmp;

	map_detected = false;
	tmp = NULL;
	fd = open_file(map_file);
	line = get_next_line(fd);
	if (!line)
		err_free_exit(EMPTY_FILE_ERR, NULL, NULL);
	while (line)
	{
		parse_line(line, data, &map_detected, &tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (tmp)
		parse_map(&tmp, data);
	if (!check_completeness(data, ALL))
		err_free_exit(INCOMPLETE_FIELD_ERR, data, NULL);
}

// This function will parse the line and call the relevant function
// depending on the data type to be stored.
void	parse_line(char *line, t_data *data, bool *map_detected, t_list **tmp)
{
	char	*s;

	s = line;
	skip_whitespace(&s);
	if (!*s && !(*map_detected))
		return ;
	else if (!(ft_strncmp(s, "NO", 2) && ft_strncmp(s, "SO", 2)
			&& ft_strncmp(s, "WE", 2) && ft_strncmp(s, "EA", 2)))
		parse_texture(s, data);
	else if (*s == 'F' || *s == 'C')
		parse_color(s, line, data);
	else if (detect_map(data, line, map_detected) || *map_detected)
		parse_map_line(line, tmp);
}

// This function will store the texture paths in their corresponding fields.
void	parse_texture(char *s, t_data *data)
{
	char	*id;
	char	*path_start;
	int		len;
	char	*trimmed_path;

	id = s;
	s += 2;
	if (!ft_strchr(WHITESPACE, *s))
		return ;
	skip_whitespace(&s);
	if (!(*s))
		return ;
	path_start = s;
	while (*s)
		s++;
	len = s - path_start;
	trimmed_path = ft_strtrim_mod(ft_substr(path_start, 0, len), WHITESPACE);
	if (!ft_strncmp(id, "NO", 2) && !data->tex.north_texture)
		data->tex.north_texture = trimmed_path;
	else if (!ft_strncmp(id, "SO", 2) && !data->tex.south_texture)
		data->tex.south_texture = trimmed_path;
	else if (!ft_strncmp(id, "WE", 2) && !data->tex.west_texture)
		data->tex.west_texture = trimmed_path;
	else if (!ft_strncmp(id, "EA", 2) && !data->tex.east_texture)
		data->tex.east_texture = trimmed_path;
}

// This function will store the floor and ceiling colors in their
// corresponding fields.
void	parse_color(char *s, char *line, t_data *data)
{
	char	id;
	char	*color_start;
	int		len;
	char	*trimmed_color;

	id = *s;
	s += 1;
	if (!ft_strchr(WHITESPACE, *s))
		return ;
	skip_whitespace(&s);
	if (!(*s))
		return ;
	color_start = s;
	while (*s)
		s++;
	len = s - color_start;
	trimmed_color = ft_strtrim_mod(ft_substr(color_start, 0, len), WHITESPACE);
	if (id == 'F' && data->tex.floor_color < 0)
		data->tex.floor_color = color_str_to_int(trimmed_color, line, data);
	else if (id == 'C' && data->tex.ceiling_color < 0)
		data->tex.ceiling_color = color_str_to_int(trimmed_color, line, data);
	free(trimmed_color);
}
