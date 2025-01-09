/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:54:26 by etien             #+#    #+#             */
/*   Updated: 2025/01/09 10:41:21 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will print out the error message to STDERR,
// free dynamically-allocated memory and exit the program.
void	err_free_exit(char *err_msg, t_map *map, char *line)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (map)
		free_map(map);
	if (line)
		free(line);
	exit(1);
}

// This function frees the map data structure.
// Other than floor_color and ceiling_color, all the other data fields
// are dynamically-allocated.
void	free_map(t_map *map)
{
	if (map)
	{
		if (map->north_texture)
			free(map->north_texture);
		if (map->south_texture)
			free(map->south_texture);
		if (map->west_texture)
			free(map->west_texture);
		if (map->east_texture)
			free(map->east_texture);
		if (map->map)
			free_double_arr(map->map);
		free(map);
	}
}

// A helper function to free double arrays.
void	free_double_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

// This is a modified version of err_free_exit.
// It will free both the temporary linked list and
// the map struct.
void	tmp_exit(char *err_msg, t_map *map, t_list **tmp)
{
		ft_lstclear(tmp, del);
		err_free_exit(err_msg, map, NULL);
}
