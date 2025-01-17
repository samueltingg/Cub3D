/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:32:22 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 13:49:05 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// A helper function that will return the file descriptor
// if the file is correctly formatted and can be opened.
int	open_file(char *map_file, t_data *data)
{
	int	fd;

	if (!check_file_extension(map_file))
		err_free_exit(EXTENSION_ERR, data, NULL);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		err_free_exit(FILE_OPEN_ERR, data, NULL);
	return (fd);
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

// This function will convert the color string to its integer representation.
int	color_str_to_int(char *color_str, char *line, t_data *data)
{
	char	**color_arr;
	int		r;
	int		g;
	int		b;

	color_arr = ft_split(color_str, ',');
	if (!check_color_format(color_arr))
	{
		free(color_str);
		free_double_arr(color_arr);
		err_free_exit(COLOR_ERR, data, line);
	}
	r = ft_atoi(color_arr[0]);
	g = ft_atoi(color_arr[1]);
	b = ft_atoi(color_arr[2]);
	free_double_arr(color_arr);
	return ((r << 16) | (g << 8) | b);
}

// This function checks that the color has been correctly formatted:
// - composed of three values
// - each value is composed of digits
// - each value has a maximum of three digits
//   (additional check to avoid integer overflow)
// - each value must be between 0 and 255
bool	check_color_format(char **color_arr)
{
	int		i;
	int		j;

	i = 0;
	while (color_arr[i])
		i++;
	if (i != 3)
		return (false);
	i = -1;
	while (color_arr[++i])
	{
		color_arr[i] = ft_strtrim_mod(color_arr[i], WHITESPACE);
		j = -1;
		while (color_arr[i][++j])
			if (!ft_isdigit(color_arr[i][j]))
				return (false);
		if (ft_strlen(color_arr[i]) > 3
			|| ft_atoi(color_arr[i]) < 0
			|| ft_atoi(color_arr[i]) > 255)
			return (false);
	}
	return (true);
}

// This function checks that the fields have been filled from the .cub file.
// The default will check for all fields, except for the map field.
// ALL mode will check for all fields.
bool	check_completeness(t_data *data, int check_all)
{
	if (!data->tex->north_texture || !data->tex->south_texture
		|| !data->tex->west_texture || !data->tex->east_texture
		|| data->tex->floor_color < 0 || data->tex->ceiling_color < 0)
	{
		if (!data->tex->north_texture)
			printf("North texture field is empty.\n");
		if (!data->tex->south_texture)
			printf("South texture field is empty.\n");
		if (!data->tex->west_texture)
			printf("West texture field is empty.\n");
		if (!data->tex->east_texture)
			printf("East texture field is empty.\n");
		if (data->tex->floor_color < 0)
			printf("Floor color field is empty.\n");
		if (data->tex->ceiling_color < 0)
			printf("Ceiling color field is empty.\n");
		return (false);
	}
	if (check_all && !data->map)
	{
		printf("No map detected.\n");
		return (false);
	}
	return (true);
}
