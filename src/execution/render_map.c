/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:38:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/17 11:34:17 by sting            ###   ########.fr       */
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

void render_player(t_vars *vars)
{
	int start_x;
	int start_y;
	
	start_x = vars->p_x * BLOCK_W - P_WIDTH / 2;
	start_y = vars->p_y * BLOCK_H - P_HEIGHT / 2;
	render_square(&vars->img, (t_rect){start_x, start_y, P_WIDTH, P_HEIGHT, RED_PIXEL});
	// render_square(&vars->img, (t_rect){vars->p_x - P_WIDTH/2, vars->p_y - P_HEIGHT/2, P_WIDTH, P_HEIGHT, RED_PIXEL});
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

void	render_map(t_vars *vars, char **map)
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
				render_square(&vars->img, (t_rect){x, y, BLOCK_W, BLOCK_H, 0xffffff});
			else
				render_square(&vars->img, (t_rect){x, y, BLOCK_W, BLOCK_H, 0x0});
			x += BLOCK_W;
			i++;
		}
		y += BLOCK_H;
		j++;
	}
	render_grid_lines(&vars->img, map_width, map_height);
    render_player(vars);
	// Render Direction Vector Line
	render_line_bresenham(&vars->img, (t_line_cord){vars->p_x * BLOCK_W, vars->p_y * BLOCK_H, vars->dir_x*BLOCK_W + vars->p_x * BLOCK_W, vars->dir_y*BLOCK_H + vars->p_y * BLOCK_H, ORANGE_PIXEL, ORANGE_PIXEL}); // ! tmp
}
