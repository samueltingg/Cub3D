/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuelting <samuelting@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:12:33 by sting             #+#    #+#             */
/*   Updated: 2025/02/13 18:21:50 by samuelting       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "parsing.h"

enum
{
	W,
	A,
	S,
	D,
	LEFT_ARR,
	RIGHT_ARR,
	MOUSE_MOVE_LEFT,
	MOUSE_MOVE_RIGHT,
};

typedef struct s_cord
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_cord;

typedef struct s_line_cord
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color1;
	int		color2;
}			t_line_cord;

typedef struct s_line_var
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;
	int		xi;
	int		yi;
}			t_line_var;

// x & y is the origin(top left) coordinatesd of the square
typedef struct t_square
{
	double	x;
	double	y;
	double	len;
	int		color;
}			t_square;

typedef struct s_ray
{
	int		win_x;
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
}			t_ray;

typedef enum e_raycasting_mode
{
	NORMAL,
	DOOR_DETECTION,
	OPEN_DOOR
}			t_raycasting_mode;

void	mlx(t_data *data);

// * RENDERING
void		img_pix_put(t_img *img, int x, int y, int color);
int			render(void *param);
void		render_square(t_img *img, t_square rect);
void		render_minimap(t_data *data, char **map);
void		render_grid_lines(t_img *img, int map_width, int map_height,
				int block_len);

// * TEXTURES
void	init_textures(t_data *data, t_texture *tex);
void		render_textures(t_data *data, t_ray ray, t_texture tex, int x);

// BRESENHAM'S LINE ALGO
void		render_line_bresenham(t_img *img, t_line_cord cord);
void		render_line_low(t_img *img, t_line_cord line);

// Handle Key Event
int			close_window(void *params);
int			handle_key_release(int keycode, void *param);
int			handle_key_press(int keycode, void *param);
void		player_movement(t_data *data, bool *keys, t_player *player);
int			mouse_hook(int x, int y, void *param);
int			handle_mouse_click(int keycode, int x, int y, void *param);
void		rotate_player(int key, t_player *player, int rotate_amt);
void		translate_player(int key, t_data *data, t_player *player);

// RAYCASTING
void		init_raycasting_info(int x, t_ray *ray, t_player player);
void		dda_setup(t_ray *ray, t_player player);
void		perform_dda(t_ray *ray, t_data *data, int raycasting_mode);
void		calc_line_height(t_ray *ray);
void		raycasting(t_data *data);

// DOOR
bool		detect_door(t_data *data, t_ray *ray);
void		update_door_variables(t_data *data, t_door *door,
				double delta_time);
void		close_door_automatically(t_data *data, t_door *door);
void		add_door_offset(t_data *data, t_ray *ray, t_texture *tex,
				double step);
void		open_door_raycasting(t_data *data);

// GRADIENT
int			gradient(int start_color, int end_color, int len, int position);

#endif
