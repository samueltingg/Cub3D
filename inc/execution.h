/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:12:33 by sting             #+#    #+#             */
/*   Updated: 2025/01/17 16:01:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "parsing.h"

typedef struct s_cord
{
	double				x;
	double				y;
	double				z;
	int					color;
}						t_cord;

typedef struct s_line_cord
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					color1;
	int					color2;
}						t_line_cord;

typedef struct s_line_var
{
	int					dx;
	int					dy;
	int					d;
	int					x;
	int					y;
	int					xi;
	int					yi;
}						t_line_var;

typedef struct s_angle
{
	double				x;
	double				y;
	double				z;
}						t_angle;

// -------Newly added--------

typedef struct s_rect
{
	double x; // origin (top left)
	double y; // origin (top left)
	double				width;
	double				height;
	int					color;
}						t_rect;
//---------------------------

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_vars
{
	char				**map;
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;

	// coordinate of player
	double				p_x;
	double				p_y;

	// raycasting section
	double				dir_x;
	double				dir_y;
	double				p_angle;
	double				plane_x;
	double				plane_y;

}						t_vars;


// * RENDERING
void					img_pix_put(t_img *img, int x, int y, int color);
void					render_background(t_img *img, int color);
int						render(void *param);
void					render_square(t_img *img, t_rect rect);
void					render_map(t_vars *vars, char **map);
void					render_grid_lines(t_img *img, int map_width,
							int map_height);

// * RAYCASTING
void					render_rays(t_vars *vars);

// BRESENHAM'S LINE ALGO
void					render_line_bresenham(t_img *img, t_line_cord cord);
void					render_line_low(t_img *img, t_line_cord line);

// * COLOR
int						gradient(int startcolor, int endcolor, int len,
							int pix);

// Handle Key Event
int						close_window(void *params);
int						handle_key_event(int keycode, void *param);
void					raycasting(t_vars *vars);

#endif