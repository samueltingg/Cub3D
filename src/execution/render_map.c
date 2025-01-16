/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:38:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/16 09:43:20 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	render_map(t_img *img, char **map)
{
	int	map_height;
	int	map_width;
	int	x;
	int	y;
	int	i;
	int	j;

	// example
	map_height = BLOCK_H * 7;
	map_width = BLOCK_W * 7;
	// example map
	y = 0;
	j = 0;
	while (y < map_height)
	{
		x = 0;
		i = 0;
		while (x < map_width)
		{
			if (map[j][i] == '1')
				render_square(img, (t_rect){x, y, BLOCK_W, BLOCK_H, 0xffffff});
			else if (map[j][i] == '0')
				render_square(img, (t_rect){x, y, BLOCK_W, BLOCK_H, 0x0});
			x += BLOCK_W;
			i++;
		}
		y += BLOCK_H;
		j++;
	}
	render_grid_lines(img, map_width, map_height);
}
