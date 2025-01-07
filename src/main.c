/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 11:06:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		err_and_exit(ARGS_ERR);
	map = map_init();
	parse_cub_file(av[1], map);
	if (map->north_texture)
		printf("%s\n", map->north_texture);
	if (map->south_texture)
		printf("%s\n", map->south_texture);
	if (map->west_texture)
		printf("%s\n", map->west_texture);
	if (map->east_texture)
		printf("%s\n", map->east_texture);
	if (map->floor_color >= 0)
		printf("%d\n", map->floor_color);
	if (map->ceiling_color >= 0)
		printf("%d\n", map->ceiling_color);
	free_map(map);
	return (0);
}
