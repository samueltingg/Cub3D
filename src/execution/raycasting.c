/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:57 by sting             #+#    #+#             */
/*   Updated: 2025/01/16 11:28:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


/*
*camera_x
- the x-cord on camera plane that cur x-cord of screen represents
- camera plane range is from -1 < x < 1

*/

// TODO: separate into functions
void raycasting(t_vars *vars)
{
    int x;
    double pos_x;
    double pos_y;
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    int step_x;
    int step_y;
    // int hit_side;
    // double perp_wall_dist;
    
    pos_x = vars->p_x / BLOCK_W;
    pos_y = vars->p_y / BLOCK_H;


    x = -1;
    while (++x < WINDOW_WIDTH)
    {
        // calculate ray position & direction
        camera_x = 2 * x / (double)WINDOW_WIDTH - 1; // x-coordinate in camera space
        ray_dir_x = vars->dir_x + (vars->plane_x * camera_x); // ! not sure: why multiply?
        ray_dir_y = vars->dir_y + (vars->plane_y * camera_x);
    
        map_x = (int)pos_x; // ? isn't p_x the scaled up ver? don't need to divide n round down?
        map_y = (int)pos_y;
        
        if (ray_dir_x == 0)
            delta_dist_x = 1e30; // avoid division of 0, hence set to high value
        else 
            delta_dist_x = fabs(1 / ray_dir_x);
        if (ray_dir_y == 0)
            delta_dist_y = 1e30;
        else 
            delta_dist_y = fabs(1 / ray_dir_y);


        //calculate step and initial sideDist
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (pos_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x= (map_x + 1.0 - pos_x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y= -1;
            side_dist_y = (pos_y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
        }

        
        //perform DDA
        while (1)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                // hit_side = EW;
            }
            else        
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                // hit_side = NS;
            }
            //Check if ray has hit a wall
            if (vars->map[map_y][map_x] == '1') // todo: store map in t_vars?
            {
                // todo: draw a line from p_x/y to map_x/y
                render_line_bresenham(&vars->img, (t_line_cord){vars->p_x, vars->p_y, map_x*BLOCK_W, map_y*BLOCK_H, GREEN_PIXEL, GREEN_PIXEL});
                break;
            }
        } 

        // Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
        // if(hit_side == 0) 
        //     perp_wall_dist = (side_dist_x - delta_dist_x);
        // else
        //     perp_wall_dist = (side_dist_y - delta_dist_y);
    }
}
