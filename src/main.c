/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 15:54:08 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		err_and_exit(ARGS_ERR);
	map = map_init();
	parse_map(av[1], map);
	printf("%s\n", map->north_texture);
	printf("%s\n", map->south_texture);
	printf("%s\n", map->west_texture);
	printf("%s\n", map->east_texture);
	return (0);
}
