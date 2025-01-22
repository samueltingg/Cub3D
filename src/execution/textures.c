/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:33:42 by sting             #+#    #+#             */
/*   Updated: 2025/01/22 14:14:13 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*
wall_x: 
  - relative position / ratio of where the ray hits the wall, 
  - value is normalized to the range [0, 1]

tex_x:
  - x cord on texture
*/
void render_textures(t_data *data, t_player player, t_ray ray)
{
    double wall_x;
    int tex_x;

    // calculate value of wallx
    if (ray.side == EW)
        wall_x = player.pos_y + ray.perp_wall_dist * ray.dir_y;
    else
        wall_x = player.pos_x + ray.perp_wall_dist * ray.dir_x;
    wall_x -= floor(wall_x);

    // calc value of tex_x
    tex_x = (int)wall_x * (double)TEX_WIDTH;
    if(ray.side == EW && ray.dir_x > 0)
        tex_x = TEX_WIDTH - tex_x - 1; // ! ??
    if(ray.side == NS && ray.dir_y < 0)
        tex_x = TEX_WIDTH - tex_x - 1; //! ??

    double step;
    double tex_pos;
    int y;
    int tex_y;
    __uint32_t color;

    step = 1.0 * TEX_HEIGHT / ray.line_height;
    tex_pos = (ray.draw_start - WINDOW_HEIGHT / 2 + ray.line_height / 2) * step;
    y = ray.draw_start;
    while (y < ray.draw_end)
    {
        (int)tex_pos & (TEX_HEIGHT - 1);
        tex_pos += step;
        // ! STOPPED HERE

        y++;
    }
}
