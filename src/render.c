/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/06 16:29:10 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_horizontal_lines(t_vars *vars, t_cord ***grid)
{
	int			j;
	int			i;
	t_line_cord	line;

	j = 0;
	while (j < vars->line_count)
	{
		i = 0;
		while (i < vars->wc - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j][i + 1].x);
			line.y2 = round((*grid)[j][i + 1].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j][i + 1].color;
			render_line_bresenham(&vars->img, line);
			i++;
		}
		j++;
	}
}

void	render_vertical_lines(t_vars *vars, t_cord ***grid)
{
	int			i;
	int			j;
	t_line_cord	line;

	i = 0;
	while (i < vars->wc)
	{
		j = 0;
		while (j < vars->line_count - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j + 1][i].x);
			line.y2 = round((*grid)[j + 1][i].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j + 1][i].color;
			render_line_bresenham(&vars->img, line);
			j++;
		}
		i++;
	}
}

void	render_grid(t_vars *vars, t_cord ***grid)
{
	render_horizontal_lines(vars, grid);
	render_vertical_lines(vars, grid);
}

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

int	render(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0xA1A1A1);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0,
		0);
	return (0);
}
