/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:22 by etien             #+#    #+#             */
/*   Updated: 2025/02/06 19:20:04 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map_data(t_data *data)
{
	if (data->tex.path[0])
		printf("North texture: %s\n", data->tex.path[0]);
	if (data->tex.path[1])
		printf("South texture: %s\n", data->tex.path[1]);
	if (data->tex.path[2])
		printf("West texture: %s\n", data->tex.path[2]);
	if (data->tex.path[3])
		printf("East texture: %s\n", data->tex.path[3]);
	if (data->tex.floor_color >= 0)
		printf("Floor color: %d\n", data->tex.floor_color);
	if (data->tex.ceiling_color >= 0)
		printf("Ceiling color: %d\n", data->tex.ceiling_color);
	if (data->map_height >= 0)
		printf("Map height: %d\n", data->map_height);
	if (data->map_width >= 0)
		printf("Map width: %d\n", data->map_width);
	printf("Player direction vector: (%f, %f)\n",
		data->player.dir_x, data->player.dir_y);
	if (data->player.pos_x >= 0)
		printf("Player x: %f\n", data->player.pos_x);
	if (data->player.pos_y >= 0)
		printf("Player y: %f\n", data->player.pos_y);
	print_map(data->map);
}

void	print_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	if (map)
	{
		printf("Map: \n");
		while (map[y])
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == 'X')
					printf("\033[31m%c\033[0m", map[y][x]);
				else if (map[y][x] == 'D')
					printf("\033[32m%c\033[0m", map[y][x]);
				else
					printf("%c", map[y][x]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
}
