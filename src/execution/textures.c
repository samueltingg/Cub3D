/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:33:42 by sting             #+#    #+#             */
/*   Updated: 2025/01/26 22:29:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_dir(int side, double dir_x, double dir_y)
{
	if (side == EW && dir_x < 0)
		return (WEST);
	else if (side == EW && dir_x > 0)
		return (EAST);
	else if (side == NS && dir_y > 0)
		return (SOUTH);
	else
		return (NORTH);
}

double	calc_wall_x(t_ray ray, t_player player)
{
	double	wall_x;

	if (ray.side == EW)
		wall_x = player.pos_y + ray.perp_wall_dist * ray.dir_y;
	else
		wall_x = player.pos_x + ray.perp_wall_dist * ray.dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	calc_tex_x(double wall_x, t_texture tex)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)tex.img[tex.dir].width);
	if (tex.dir == WEST || tex.dir == SOUTH)
		tex_x = tex.img[tex.dir].width - tex_x - 1; //! ??
	return (tex_x);
}

/*
wall_x:
  - relative position / ratio of where the ray hits the wall,
  - value is a fractional part along  wall axis, normalized to range [0,1]

tex_x: x cord on texture

step: vertical increment in texture space for each pixel in the column
*/
void	render_textures(t_data *data, t_ray ray, t_texture tex, int win_x)
{
	double	wall_x;
	double	step;
	int		win_y;
	int		color;

	wall_x = calc_wall_x(ray, data->player);
	tex.dir = find_dir(ray.side, ray.dir_x, ray.dir_y);
	tex.x = calc_tex_x(wall_x, tex);
	step = 1.0 * tex.img[tex.dir].height / ray.line_height;
	// starting texture coordinate
	tex.pos = (ray.draw_start - WINDOW_HEIGHT / 2 + ray.line_height / 2) * step;
	add_door_offset(data, &ray);
	win_y = ray.draw_start;
	while (win_y < ray.draw_end)
	{
		tex.y = (int)tex.pos & (tex.img[tex.dir].height - 1); //! ?
		tex.pos += step;
		color = tex.img[tex.dir].addr[(tex.y * tex.img[tex.dir].width) + tex.x];
		if (ray.side == EW)
			color = (color >> 1) & DARKEN_COLOR_MASK; //! ?
		img_pix_put(&data->img, win_x, win_y, color);
		win_y++;
	}
}
