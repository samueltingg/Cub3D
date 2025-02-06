/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:38:32 by sting             #+#    #+#             */
/*   Updated: 2025/02/06 15:33:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_square(t_img *img, t_square rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y <= rect.len + rect.y)
	{
		x = rect.x;
		while (x <= rect.len + rect.x)
		{
			img_pix_put(img, x, y, rect.color);
			x++;
		}
		y++;
	}
}

void	render_player(t_data *data, t_player player, int block_len)
{
	int	start_x;
	int	start_y;
	int	player_len;

	player_len = block_len * 3 / 5;
	start_x = player.pos_x * block_len - player_len / 2;
	start_y = player.pos_y * block_len - player_len / 2;
	render_square(&data->img, (t_square){start_x, start_y, player_len,
		RED_PIXEL});
	render_line_bresenham(&data->img, (t_line_cord){player.pos_x * block_len,
		player.pos_y * block_len, player.dir_x * block_len + player.pos_x
		* block_len, player.dir_y * block_len + player.pos_y * block_len,
		RED_PIXEL, RED_PIXEL});
}

void	render_grid_lines(t_img *img, int map_width, int map_height,
		int block_len)
{
	int	x;
	int	y;

	x = block_len;
	while (x < map_width)
	{
		y = 0;
		while (y < map_height)
		{
			img_pix_put(img, x, y, L_GREY_PIXEL);
			y++;
		}
		x += block_len;
	}
	y = block_len;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			img_pix_put(img, x, y, L_GREY_PIXEL);
			x++;
		}
		y += block_len;
	}
}

// Dynamic minimap size: "WINDOW_HEIGHT * O.3"
void	render_minimap(t_data *data, char **map)
{
	int	i;
	int	j;
	int	block_len;

	block_len = (WINDOW_HEIGHT * 0.3) / data->map_height;
	j = -1;
	while (++j < data->map_height)
	{
		i = -1;
		while (++i < data->map_width)
		{
			if (map[j][i] == '1')
				render_square(&data->img, (t_square){i * block_len, j
					* block_len, block_len, WHITE_PIXEL});
			else if (map[j][i] == 'D')
			{
				render_square(&data->img, (t_square){i * block_len, j
					* block_len, block_len, YELLOW_PIXEL});
				if (j == data->door.y && i == data->door.x
					&& data->door.progress > 0)
					render_square(&data->img, (t_square){i * block_len, j
						* block_len, block_len, gradient(YELLOW_PIXEL,
							GREEN_PIXEL, 100, data->door.progress * 100)});
			}
		}
	}
	render_grid_lines(&data->img, data->map_width * block_len, data->map_height
		* block_len, block_len);
	render_player(data, data->player, block_len);
}
