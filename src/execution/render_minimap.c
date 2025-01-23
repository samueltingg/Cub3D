/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:38:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/23 17:28:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_square(t_img *img, t_rect rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y <= rect.height + rect.y)
	{
		x = rect.x;
		while (x <= rect.width + rect.x)
		{
			img_pix_put(img, x, y, rect.color);
			x++;
		}
		y++;
	}
}

void	render_player(t_data *data, t_player player)
{
	int	start_x;
	int	start_y;

	start_x = player.pos_x * BLOCK_W - P_WIDTH / 2;
	start_y = player.pos_y * BLOCK_H - P_HEIGHT / 2;
	render_square(&data->img, (t_rect){start_x, start_y, P_WIDTH, P_HEIGHT,
		RED_PIXEL});
	render_line_bresenham(&data->img, (t_line_cord){player.pos_x * BLOCK_W,
		player.pos_y * BLOCK_H, player.dir_x * BLOCK_W + player.pos_x * BLOCK_W,
		player.dir_y * BLOCK_H + player.pos_y * BLOCK_H, RED_PIXEL, RED_PIXEL});
}

void	render_grid_lines(t_img *img, int map_width, int map_height)
{
	int	x;
	int	y;

	// Draw vertical lines
	x = BLOCK_W;
	while (x < map_width)
	{
		y = 0;
		while (y < map_height)
		{
			img_pix_put(img, x, y, 0xA1A1A1); // Black grid line
			y++;
		}
		x += BLOCK_W;
	}
	// Draw horizontal lines
	y = BLOCK_H;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			img_pix_put(img, x, y, 0xA1A1A1); // Black grid line
			x++;
		}
		y += BLOCK_H;
	}
}

void	render_minimap(t_data *data, char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	j = 0;
	while (y < data->map_height * BLOCK_H)
	{
		x = 0;
		i = 0;
		while (x < data->map_width * BLOCK_H)
		{
			if (map[j][i] == '1')
				render_square(&data->img, (t_rect){x, y, BLOCK_W, BLOCK_H,
					0xffffff});
			x += BLOCK_W;
			i++;
		}
		y += BLOCK_H;
		j++;
	}
	render_grid_lines(&data->img, data->map_width * BLOCK_H, data->map_height
		* BLOCK_H);
	render_player(data, data->player);
}
			// else
			// 	render_square(&data->img, (t_rect){x, y, BLOCK_W, BLOCK_H,
			// 		data->tex.ceiling_color});
