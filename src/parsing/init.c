/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 11:50:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"



// This function initializes the map data structure.
t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		err_free_exit(MAP_MALLOC_ERR, NULL, NULL);
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->map_height = -1;
	map->map_width = -1;
	map->map = NULL;
	map->pos_x = -1;
	map->pos_y = -1;
	map->dir_x = 0;
	map->dir_y = 0;
	map->plane_x = 0;
	return (map);
}

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		err_free_exit(MALLOC_ERR, NULL, NULL);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img = img_init();
	data->ray = ray_init();
	data->player = player_init();
	data->tex = tex_init();
	data->map = NULL;
	data->map_height = -1;
	data->map_width = -1;
	return (data);
}

t_img	*img_init(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		err_free_exit(MALLOC_ERR, NULL, NULL);
	ft_bzero(img, sizeof(t_img));
	return (img);
}

t_ray	*ray_init(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		err_free_exit(MALLOC_ERR, NULL, NULL);
	ft_bzero(ray, sizeof(t_ray));
	return (ray);
}


t_player	*player_init(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		err_free_exit(MALLOC_ERR, NULL, NULL);
	ft_bzero(player, sizeof(t_player));
	return (player);
}
