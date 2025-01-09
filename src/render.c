/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/09 14:05:02 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	render_horizontal_lines(t_vars *vars, t_cord ***grid)
// {
// 	int			j;
// 	int			i;
// 	t_line_cord	line;

// 	j = 0;
// 	while (j < vars->line_count)
// 	{
// 		i = 0;
// 		while (i < vars->wc - 1)
// 		{
// 			line.x1 = round((*grid)[j][i].x);
// 			line.y1 = round((*grid)[j][i].y);
// 			line.x2 = round((*grid)[j][i + 1].x);
// 			line.y2 = round((*grid)[j][i + 1].y);
// 			line.color1 = (*grid)[j][i].color;
// 			line.color2 = (*grid)[j][i + 1].color;
// 			render_line_bresenham(&vars->img, line);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	render_vertical_lines(t_vars *vars, t_cord ***grid)
// {
// 	int			i;
// 	int			j;
// 	t_line_cord	line;

// 	i = 0;
// 	while (i < vars->wc)
// 	{
// 		j = 0;
// 		while (j < vars->line_count - 1)
// 		{
// 			line.x1 = round((*grid)[j][i].x);
// 			line.y1 = round((*grid)[j][i].y);
// 			line.x2 = round((*grid)[j + 1][i].x);
// 			line.y2 = round((*grid)[j + 1][i].y);
// 			line.color1 = (*grid)[j][i].color;
// 			line.color2 = (*grid)[j + 1][i].color;
// 			render_line_bresenham(&vars->img, line);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	render_grid(t_vars *vars, t_cord ***grid)
// {
// 	render_horizontal_lines(vars, grid);
// 	render_vertical_lines(vars, grid);
// }

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

#define IMG_W 100
#define IMG_H 100

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

void	render_grid_lines(t_img *img, int map_width, int map_height)
{
	int x;
	int y;

	// Draw vertical lines
	x = IMG_W;
	while (x < map_width)
	{
		y = 0;
		while (y < map_height)
		{
			img_pix_put(img, x, y, 0xA1A1A1); // Black grid line
			y++;
		}
		x += IMG_W;
	}
	// Draw horizontal lines
	y = IMG_H;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			img_pix_put(img, x, y, 0xA1A1A1); // Black grid line
			x++;
		}
		y += IMG_H;
	}
}

void	render_map(t_img *img)
{
	int		map_height;
	int		map_width;
	char	*map[] = {
		"1111111",
		"1001001",
		"1001001",
		"1001001",
		"1000001",
		"1000001",
		"1111111",
		NULL};
	int		x;
	int		y;
	int		i; 
	int		j;

	// example
	map_height = IMG_H * 7;
	map_width = IMG_W * 7;
	// example map
	y = 0;
	j = 0;
	while (y < map_height) // !  < or <= ??
	{
		x = 0;
		i = 0;
		while (x < map_width) // !  < or <= ??
		{
			if (map[j][i] == '1')
				render_square(img, (t_rect){x, y, IMG_W, IMG_H, 0xffffff});
			else if (map[j][i] == '0')
				render_square(img, (t_rect){x, y, IMG_W, IMG_H, 0x0});
			x += IMG_W;
			i++;
		}
		y += IMG_H;
		j++;
	}
	render_grid_lines(img, map_width, map_height);
}

void render_player(t_vars *vars)
{
	render_square(&vars->img, (t_rect){vars->p_x, vars->p_y, 25, 25, RED_PIXEL});
}

void render_rays(t_vars *vars)
{
	render_line_bresenham(&vars->img, (t_line_cord){vars->p_x, vars->p_y, 150, 120, GREEN_PIXEL, GREEN_PIXEL});
}

int	render(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0xA1A1A1);
	render_map(&vars->img);
	render_player(vars);
	render_rays(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0,
		0);
	return (0);
}
