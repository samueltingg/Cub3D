/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:57 by sting             #+#    #+#             */
/*   Updated: 2025/01/10 14:39:11 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void render_rays(t_vars *vars)
{
	render_line_bresenham(&vars->img, (t_line_cord){vars->p_x + P_WIDTH/2, vars->p_y + P_HEIGHT/2, 150, 120, GREEN_PIXEL, GREEN_PIXEL});
}

/*
*camera_x
- the x-cord on camera plane that cur x-cord of screen represents
- camera plane range is from -1 < x < 1

*/
void raycasting(t_vars *vars)
{
    int x;
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;

    x = -1;
    while (++x < WINDOW_WIDTH)
    {
        // calculate ray position & direction
        camera_x = 2 * x / (double)WINDOW_WIDTH - 1; // x-coordinate in camera space
        ray_dir_x = vars->dir_x + (vars->plane_x * camera_x); // ! not sure: why multiply?
        ray_dir_y = vars->dir_y + (vars->plane_y * camera_x);
   
    }
    
    
}