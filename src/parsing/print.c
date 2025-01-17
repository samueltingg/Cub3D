/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:22 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 10:59:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map_data(t_map *map)
{
	if (map->north_texture)
		printf("North texture: %s\n", map->north_texture);
	if (map->south_texture)
		printf("South texture: %s\n", map->south_texture);
	if (map->west_texture)
		printf("West texture: %s\n", map->west_texture);
	if (map->east_texture)
		printf("East texture: %s\n", map->east_texture);
	if (map->floor_color >= 0)
		printf("Floor color: %d\n", map->floor_color);
	if (map->ceiling_color >= 0)
		printf("Ceiling color: %d\n", map->ceiling_color);
	if (map->map_height >= 0)
		printf("Map height: %d\n", map->map_height);
	if (map->map_width >= 0)
		printf("Map width: %d\n", map->map_width);
	printf("Player direction vector: (%f, %f)\n", map->dir_x, map->dir_y);
	if (map->pos_x >= 0)
		printf("Player x: %f\n", map->pos_x);
	if (map->pos_y >= 0)
		printf("Player y: %f\n", map->pos_y);
	print_map(map);
}

void	print_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	if (map->map)
	{
		printf("Map: \n");
		while (map->map[y])
		{
			x = 0;
			while (map->map[y][x])
			{
				if (map->map[y][x] == 'X')
					printf("\033[31m%c\033[0m", map->map[y][x]);
				else
					printf("%c", map->map[y][x]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
}

void	print_unclosed_map(t_map *map, int y, int x, int edge_dir)
{
	const char	*edge_dir_name[] = {"LEFT", "RIGHT", "TOP", "BOTTOM"};

	map->map[y][x] = 'X';
	print_map(map);
	printf("Unclosed map at %s edge: (y: %d, x: %d)\n",
		edge_dir_name[edge_dir], y, x);
}
