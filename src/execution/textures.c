/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:33:42 by sting             #+#    #+#             */
/*   Updated: 2025/01/23 11:55:20 by sting            ###   ########.fr       */
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
void render_textures(t_data *data, t_player player, t_ray ray, t_texture tex)
{
	//* TESTING
	// t_img tex_img;
	// char	*relative_path = "./textures/East.xpm";
	// int		img_width;
	// int		img_height;


	// tex_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, relative_path, &img_width, &img_height);
    // tex_img.addr = mlx_get_data_addr(tex_img.img_ptr,
	// 		&tex_img.bits_per_pixel, &tex_img.line_len, &tex_img.endian);
    //* ---------------------------------------

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
    // __uint32_t color;

    step = 1.0 * TEX_HEIGHT / ray.line_height;
    // starting texture coordinate
    tex_pos = (ray.draw_start - WINDOW_HEIGHT / 2 + ray.line_height / 2) * step;
    y = ray.draw_start;
    while (y < ray.draw_end)
    {
        tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
        tex_pos += step;
        // ! STOPPED HERE

        // todo: change color of specific cord on mlx_img to color of specific cord on tex
        img_pix_put(&data->img, wall_x, y, tex.img.addr[(tex_y * tex.width) + tex_x * (tex.img.bits_per_pixel / 8)]);

        y++;
    }
}


// void render_texture(t_data *data, t_player player, t_ray ray, int x)
// {
//     t_ver_line line;

//     line.x = x;
    
// }