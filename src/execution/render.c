/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/16 10:04:16 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	render_square(&vars->img, (t_rect){vars->p_x - P_WIDTH/2, vars->p_y - P_HEIGHT/2, P_WIDTH, P_HEIGHT, RED_PIXEL});
}

int	render(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0xA1A1A1);
	render_map(&vars->img, vars->map);
	render_player(vars);
	raycasting(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0,
		0);
	return (0);
}
