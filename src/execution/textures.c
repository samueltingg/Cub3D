/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:33:42 by sting             #+#    #+#             */
/*   Updated: 2025/01/23 14:52:14 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*
wall_x: 
  - relative position / ratio of where the ray hits the wall, 
  - value is a fractional part along the wall axis, normalized to the range [0, 1]

tex_x: x cord on texture

step: vertical increment in texture space for each pixel in the column
*/
void render_textures(t_data *data, t_ray ray, t_texture tex, int win_x)
{
    double wall_x;
    int tex_x;
    double step;
    double tex_pos;
    int win_y;
    int tex_y;

    // calculate value of wallx
    if (ray.side == EW)
        wall_x = data->player.pos_y + ray.perp_wall_dist * ray.dir_y;
    else
        wall_x = data->player.pos_x + ray.perp_wall_dist * ray.dir_x;
    wall_x -= floor(wall_x);
    printf("wall_x: %f\n", wall_x);
    // calc value of tex_x
    tex_x = (int)(wall_x * (double)tex.width);
    if(ray.side == EW && ray.dir_x > 0)
        tex_x = tex.width - tex_x - 1; // ! ??
    if(ray.side == NS && ray.dir_y < 0)
        tex_x = tex.width - tex_x - 1; //! ??
    printf("tex_x: %d\n", tex_x);


    // __uint32_t color;

    step = 1.0 * tex.height / ray.line_height;
    // starting texture coordinate
    tex_pos = (ray.draw_start - WINDOW_HEIGHT / 2 + ray.line_height / 2) * step;
    win_y = ray.draw_start;
    while (win_y < ray.draw_end)
    {
        tex_y = (int)tex_pos & (tex.height - 1);
        tex_pos += step;
        // ! STOPPED HERE

        // todo: change color of specific cord on mlx_img to color of specific cord on tex
        img_pix_put(&data->img, win_x, win_y, tex.img.addr[(tex_y * tex.img.line_len) + tex_x * (tex.img.bits_per_pixel / 8)]);
        win_y++;
    }
}
