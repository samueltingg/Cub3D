/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 16:44:00 by etien            ###   ########.fr       */
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
	data->map_height = -1;
	data->map_width = -1;
	data->map = NULL;
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
	texture->north_texture = NULL;
	texture->south_texture = NULL;
	texture->west_texture = NULL;
	texture->east_texture = NULL;
	texture->floor_color = -1;
	texture->ceiling_color = -1;
}
