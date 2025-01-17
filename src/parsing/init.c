/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 14:31:03 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		err_free_exit(MALLOC_ERR, NULL, NULL);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img = img_init(data);
	data->ray = ray_init(data);
	data->player = player_init(data);
	data->tex = texture_init(data);
	data->map_height = -1;
	data->map_width = -1;
	data->map = NULL;
	return (data);
}

t_img	*img_init(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		err_free_exit(MALLOC_ERR, data, NULL);
	ft_bzero(img, sizeof(t_img));
	return (img);
}

t_ray	*ray_init(t_data *data)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		err_free_exit(MALLOC_ERR, data, NULL);
	ft_bzero(ray, sizeof(t_ray));
	return (ray);
}

t_player	*player_init(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		err_free_exit(MALLOC_ERR, data, NULL);
	player->pos_x = -1;
	player->pos_y = -1;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return (player);
}

t_texture	*texture_init(t_data *data)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		err_free_exit(MALLOC_ERR, data, NULL);
	texture->north_texture = NULL;
	texture->south_texture = NULL;
	texture->west_texture = NULL;
	texture->east_texture = NULL;
	texture->floor_color = -1;
	texture->ceiling_color = -1;
	return (texture);
}
