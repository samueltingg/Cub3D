/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:57 by sting             #+#    #+#             */
/*   Updated: 2025/01/17 11:44:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// void    render_vertical_line(int x, int draw_start, int draw_end, int color)
// {
//     while ()
// }

/*
*camera_x
- the x-cord on camera plane that cur x-cord of screen represents
- camera plane range is from -1 < x < 1

*/

// TODO: separate into functions
// void raycasting(t_vars *vars)
// {
//     int x;
//     double camera_x;
//     double ray_dir_x;
//     double ray_dir_y;
//     int map_x;
//     int map_y;
//     double side_dist_x;
//     double side_dist_y;
//     double delta_dist_x;
//     double delta_dist_y;
//     int step_x;
//     int step_y;
//     int hit_side;
//     double perp_wall_dist;
    
//     x = -1;
//     while (++x < WINDOW_WIDTH)
//     {
//         // calculate ray position & direction
//         camera_x = 2 * x / (double)WINDOW_WIDTH - 1; // x-coordinate in camera space
//         ray_dir_x = vars->dir_x + (vars->plane_x * camera_x); // ! not sure: why multiply?
//         ray_dir_y = vars->dir_y + (vars->plane_y * camera_x);
    
//         map_x = (int)vars->p_x; // ? isn't p_x the scaled up ver? don't need to divide n round down?
//         map_y = (int)vars->p_y;
        
//         if (ray_dir_x == 0)
//             delta_dist_x = 1e30; // avoid division of 0, hence set to high value
//         else 
//             delta_dist_x = fabs(1 / ray_dir_x);
//         if (ray_dir_y == 0)
//             delta_dist_y = 1e30;
//         else 
//             delta_dist_y = fabs(1 / ray_dir_y);


//         //calculate step and initial sideDist
//         if (ray_dir_x < 0)
//         {
//             step_x = -1;
//             side_dist_x = (vars->p_x - map_x) * delta_dist_x;
//         }
//         else
//         {
//             step_x = 1;
//             side_dist_x= (map_x + 1.0 - vars->p_x) * delta_dist_x;
//         }
//         if (ray_dir_y < 0)
//         {
//             step_y= -1;
//             side_dist_y = (vars->p_y - map_y) * delta_dist_y;
//         }
//         else
//         {
//             step_y = 1;
//             side_dist_y = (map_y + 1.0 - vars->p_y) * delta_dist_y;
//         }
        
//         //perform DDA
//         while (1)
//         {
//             //jump to next map square, either in x-direction, or in y-direction
//             if (side_dist_x < side_dist_y)
//             {
//                 side_dist_x += delta_dist_x;
//                 map_x += step_x;
//                 hit_side = EW;
//             }
//             else        
//             {
//                 side_dist_y += delta_dist_y;
//                 map_y += step_y;
//                 hit_side = NS;
//             }
//             //Check if ray has hit a wall
//             if (vars->map[map_y][map_x] == '1') // todo: store map in t_vars?
//             {
//                 // todo: draw a line from p_x/y to map_x/y
//                 // render_line_bresenham(&vars->img, (t_line_cord){vars->p_x, vars->p_y, map_x*BLOCK_W, map_y*BLOCK_H, GREEN_PIXEL, GREEN_PIXEL});
//                 break;
//             }
//         } 

//         // Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
//         if(hit_side == EW) 
//             perp_wall_dist = (side_dist_x - delta_dist_x);
//         else if (hit_side == NS)
//             perp_wall_dist = (side_dist_y - delta_dist_y);

//         int line_height;
//         int draw_start;
//         int draw_end;

//         line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
//         draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
//         if (draw_start < 0)
//             draw_start = 0;
//         draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
//         if (draw_end >= WINDOW_HEIGHT)
//             draw_end = WINDOW_HEIGHT - 1;        
        
//         // draw vertical line
//         render_line_bresenham(&vars->img, (t_line_cord){x, draw_start, x, draw_end, BLUE_PIXEL, BLUE_PIXEL});

//     }
// }

void raycasting(t_vars *vars)
{
    int x;
    t_ray ray;
    
    x = -1;
    while (++x < WINDOW_WIDTH)
    {
        // calculate ray position & direction
        ray.camera_x = 2 * x / (double)WINDOW_WIDTH - 1; // x-coordinate in camera space
        ray.dir_x = vars->dir_x + (vars->plane_x * ray.camera_x); 
        ray.dir_y = vars->dir_y + (vars->plane_y * ray.camera_x);
    
        ray.map_x = (int)vars->p_x;
        ray.map_y = (int)vars->p_y;
        
        if (ray.dir_x == 0)
            ray.delta_dist_x = 1e30; // avoid division of 0, hence set to high value
        else 
            ray.delta_dist_x = fabs(1 / ray.dir_x);
        if (ray.dir_y == 0)
            ray.delta_dist_y = 1e30;
        else 
            ray.delta_dist_y = fabs(1 / ray.dir_y);

        //calculate step and initial sideDist
        if (ray.dir_x < 0)
        {
            ray.step_x = -1;
            ray.side_dist_x = (vars->p_x - ray.map_x) * ray.delta_dist_x;
        }
        else
        {
            ray.step_x = 1;
            ray.side_dist_x = (ray.map_x + 1.0 - vars->p_x) * ray.delta_dist_x;
        }
        if (ray.dir_y < 0)
        {
            ray.step_y = -1;
            ray.side_dist_y = (vars->p_y - ray.map_y) * ray.delta_dist_y;
        }
        else
        {
            ray.step_y = 1;
            ray.side_dist_y = (ray.map_y + 1.0 - vars->p_y) * ray.delta_dist_y;
        }
        
        //perform DDA
        while (1)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if (ray.side_dist_x < ray.side_dist_y)
            {
                ray.side_dist_x += ray.delta_dist_x;
                ray.map_x += ray.step_x;
                ray.side = EW;
            }
            else        
            {
                ray.side_dist_y += ray.delta_dist_y;
                ray.map_y += ray.step_y;
                ray.side = NS;
            }
            //Check if ray has hit a wall
            if (vars->map[ray.map_y][ray.map_x] == '1')
            {
                break;
            }
        } 

        // Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
        if(ray.side == EW) 
            ray.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x);
        else if (ray.side == NS)
            ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y);

        ray.line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
        ray.draw_start = -ray.line_height / 2 + WINDOW_HEIGHT / 2;
        if (ray.draw_start < 0)
            ray.draw_start = 0;
        ray.draw_end = ray.line_height / 2 + WINDOW_HEIGHT / 2;
        if (ray.draw_end >= WINDOW_HEIGHT)
            ray.draw_end = WINDOW_HEIGHT - 1;        
        
        // draw vertical line
        render_line_bresenham(&vars->img, (t_line_cord){x, ray.draw_start, x, ray.draw_end, BLUE_PIXEL, BLUE_PIXEL});
    }
}
