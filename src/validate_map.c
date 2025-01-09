/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/09 14:06:45 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	validate_map(t_map *map)
{
	store_player(map);
	if (map->player_dir < 0)
		err_free_exit(PLAYER_MISSING_ERR, map, NULL);
	validate_boundaries(map);
}

// This function will ensure that there is only one player
// in the map and store the player's direction and position.
void	store_player(t_map *map)
{
	int	i;
	int j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (ft_strchr(DIRECTIONS, map->map[i][j]))
			{
				if (map->player_dir < 0)
				{
					if (map->map[i][j] == 'N')
						map->player_dir = NORTH;
					if (map->map[i][j] == 'S')
						map->player_dir = SOUTH;
					if (map->map[i][j] == 'W')
						map->player_dir = WEST;
					if (map->map[i][j] == 'E')
						map->player_dir = EAST;
					map->player_x = j;
					map->player_y = i;
				}
				else
					err_free_exit(PLAYER_COUNT_ERR, map, NULL);
			}
		}
	}
}

void	validate_boundaries(t_map *map)
{
	if (!check_left_right_edge(map))
		err_free_exit(MAP_BOUNDARIES_ERR, map, NULL);
	printf("Left and right edges are closed.\n");
	// if (!check_top_bottom_rows(map))
	// 	err_free_exit(MAP_BOUNDARIES_ERR, map, NULL);
	// printf("Top and bottom rows are closed.\n");
}

// This function checks that the left and right edge of each
// row are walls after skipping over the leading and trailing
// whitespaces.
bool	check_left_right_edge(t_map *map)
{
	char	*left_edge;
	char	*right_edge;
	int		i;

	i = -1;
	while (map->map[++i])
	{
		left_edge = map->map[i];
		right_edge = map->map[i];
		skip_whitespace(&left_edge);
		skip_whitespace_rev(&right_edge);
		if (*left_edge != '1' || *right_edge != '1')
			return (false);
	}
	return (true);
}



// This function checks that the top and bottom rows are only composed
// of walls after trimming leading and trailing whitespaces.
bool	check_top_bottom_rows(t_map *map)
{
	char *trimmed_top;
	char *trimmed_bottom;

	trimmed_top = ft_strtrim(map->map[0], WHITESPACE);
	trimmed_bottom = ft_strtrim(map->map[map->map_height - 1], WHITESPACE);
	if (!only_walls(trimmed_top) || !only_walls(trimmed_bottom))
		return (free(trimmed_top), free(trimmed_bottom), false);
	return (free(trimmed_top), free(trimmed_bottom), true);
}

// This function checks that the string is composed entirely of '1's.
bool only_walls(char *s)
{
	while (*s)
	{
		if (*s != '1')
			return (false);
		s++;
	}
	return (true);
}
