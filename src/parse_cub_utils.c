/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:32:22 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 11:43:36 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
void	color_str_to_int(char *color_str, int *color_int)
{
	char	**color_arr;
	int		r;
	int		g;
	int		b;

	color_arr = ft_split(color_str, ',');
	if (!check_color_format(color_arr))
		err_and_exit(COLOR_ERR);
	r = ft_atoi(color_arr[0]);
	g = ft_atoi(color_arr[1]);
	b = ft_atoi(color_arr[2]);
	*color_int = (r << 16) | (g << 8) | b;
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

// This function checks that the fields have been filled from the .cub file.
// The default will check for all fields, except for the map field.
// ALL mode will check for all fields.
bool	check_completeness(t_map *map, int check_all)
{
	if (!map->north_texture || !map->south_texture
	|| !map->west_texture || !map->east_texture
	|| map->floor_color < 0 || map->ceiling_color < 0)
		return (false);
	if (check_all && !map->map)
		return (false);
	return (true);
}
