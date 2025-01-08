/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/08 18:20:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	if (map->north_texture)
		printf("North texture: \n%s\n", map->north_texture);
	if (map->south_texture)
		printf("South texture: \n%s\n", map->south_texture);
	if (map->west_texture)
		printf("West texture: \n%s\n", map->west_texture);
	if (map->east_texture)
		printf("East texture: \n%s\n", map->east_texture);
	if (map->floor_color >= 0)
		printf("Floor color: \n%d\n", map->floor_color);
	if (map->ceiling_color >= 0)
		printf("Ceiling color: \n%d\n", map->ceiling_color);
	if (map->map_height >= 0)
		printf("Map height: \n%d\n", map->map_height);
	if (map->map_width >= 0)
		printf("Map width: \n%d\n", map->map_width);
	i = -1;
	if (map->map)
		while (map->map[++i])
			printf("%s\n", map->map[i]);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		err_free_exit(ARGS_ERR, NULL, NULL);
	map = map_init();
	parse_cub_file(av[1], map);
	print_map(map);
	free_map(map);
	return (0);
}
