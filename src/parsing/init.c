/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/02/05 10:54:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	data_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	img_init(&data->img);
	player_init(&data->player);
	texture_init(&data->tex);
	door_init(&data->door);
	data->map_height = -1;
	data->map_width = -1;
	data->map = NULL;
	ft_bzero(&data->last_time, sizeof(&data->last_time));
	ft_bzero(&data->keys, sizeof(&data->keys));
}

void	img_init(t_img *img)
{
	ft_bzero(img, sizeof(t_img));
}

void	player_init(t_player *player)
{
	player->pos_x = -1;
	player->pos_y = -1;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	texture_init(t_texture *texture)
{
	ft_bzero(texture->path, sizeof(texture->path));
	texture->floor_color = -1;
	texture->ceiling_color = -1;
	ft_bzero(texture->img, sizeof(texture->img));
	texture->dir = 0;
	texture->x = 0;
	texture->y = 0;
	texture->pos = 0;
}

void	door_init(t_door *door)
{
	door->door_count = 0;
	door->x = -1;
	door->y = -1;
	door->is_open = 0;
	door->progress = 0;
	door->time_elapsed = 0;
}
