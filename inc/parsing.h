/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:24 by etien             #+#    #+#             */
/*   Updated: 2025/02/07 15:58:18 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include <time.h>

# define DIRECTIONS "NSEW"
# define DOOR_EMPTY_SPACE "0 NSEW"
# define EMPTY_SPACE "0 "
# define DATA_ELEMENTS "01NSEWFC"
# define MAP_ELEMENTS "01NSEW "
# define OBSTACLE "1D"
# define WHITESPACE " \t\n"

// error messages
# define ARGS_ERR "Incorrect number of arguments."
# define COLOR_ERR "Invalid color."
# define CUB_EXTENSION_ERR "File name should end with .cub extension."
# define DUPLICATE_COLOR_ERR "Color field repeated."
# define DUPLICATE_TEXTURE_ERR "Texture field repeated."
# define EMPTY_FILE_ERR "File is empty."
# define FILE_OPEN_ERR "File could not be opened."
# define INCOMPLETE_FIELD_ERR "Incomplete fields."
# define INVALID_LINE_ERR "Invalid line in file."
# define MAP_ARR_MALLOC_ERR "Map array malloc failure."
# define MAP_BOUNDARIES_ERR "Map boundaries are unclosed."
# define MAP_ELEMENT_ERR "Invalid map element."
# define MAP_EMPTY_LINE_ERR "Map should not contain empty lines."
# define MAP_ORDER_ERR "Map should be the last element."
# define PLAYER_COUNT_ERR "Only one player is allowed."
# define PLAYER_MISSING_ERR "No player found in the map."
# define TEXTURE_OPEN_ERR "Texture file could not be opened."
# define XPM_EXTENSION_ERR "The program only supports .xpm files for textures."

/**
 * @param line_len amount of bytes taken by one row of our image
 * @param img_ptr pointer to the image structure created by mlx_new_image
 * @param addr pointer to the raw pixel data of the image
 */
typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_texture
{
	char	*path[4];
	int		floor_color;
	int		ceiling_color;
	t_img	img[4];
	int		dir;
	int		x;
	int		y;
	double	pos;
}			t_texture;

typedef struct s_door
{
	int		door_count;
	int		x;
	int		y;
	int		is_open;
	double	progress;
	double	time_elapsed;
}			t_door;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_player		player;
	t_texture		tex;
	t_door			door;
	int				map_height;
	int				map_width;
	char			**map;
	struct timeval	last_time;
	bool			keys[6];
	bool			mouse_movement_flag;
}					t_data;

typedef struct s_map_copy
{
	int		height;
	int		width;
	char	**map;
}	t_map_copy;

typedef enum e_completeness_check
{
	MAP_IS_LAST,
	ALL
}	t_completeness_check;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

typedef struct s_coords
{
	int	y;
	int	x;
}		t_coords;

void		data_init(t_data *data);
void		img_init(t_img *img);
void		player_init(t_player *player);
void		texture_init(t_texture *texture);
void		door_init(t_door *door);

void		print_map_data(t_data *data);
void		print_map(char **map);

void		err_free_exit(char *err_msg, t_data *data, char *line);
void		free_data(t_data *data);
void		free_double_arr(char **arr);
void		tmp_exit(char *err_msg, t_data *data, t_list **tmp);

void		parse_cub(char *map_file, t_data *data);
void		parse_line(char *line, t_data *data, bool *map_detected,
				t_list **tmp);
void		parse_texture(char *s, char *line, t_data *data);
void		assign_texture(char *id, char *trimmed_path, char *line,
				t_data *data);
void		parse_color(char *s, char *line, t_data *data);

int			open_file(char *map_file);
bool		check_file_extension(const char *filename,
				const char *extension);
int			color_str_to_int(char *color_str, char *line, t_data *data);
bool		check_color_format(char **color_arr);
bool		check_completeness(t_data *data, int check_all);

void		parse_map_line(char *line, t_list **tmp);
void		parse_map(t_list **tmp, t_data *data);
int			get_min_leading_spaces(t_list *current);
void		store_map(t_list **tmp, t_data *data);
void		pad_map(t_data *data, t_list *current, int i);

bool		detect_map(t_data *data, char *line, bool *map_detected);
bool		line_is_empty(char *s);
void		remove_trailing_empty_lines(t_list *tmp);
bool		check_empty_lines(t_list *tmp);
bool		check_map_elements(t_list *tmp);

void		validate_map(t_data *data);
void		validate_player(t_data *data);
void		validate_boundaries(t_data *data);
void		validate_textures(t_data *data);

void		store_player(t_data *data, int y, int x, int *player_count);
void		store_vectors(t_player *player, char c);
void		store_dir(t_player *player, double dir_x, double dir_y);
void		store_plane(t_player *player, double plane_x, double plane_y);
bool		texture_is_accessible(const char *path);

t_map_copy	copy_map(char **map, int height, int width);
bool		check_unclosed_walls(t_map_copy *map_copy, int y, int x);
bool		on_map_boundary(t_data *data, int y, int x);

void		set_up_door(t_data	*data);
void		get_door_candidates(t_data *data, t_coords *candidates);
bool		valid_door_candidate(t_data *data, int y, int x);
void		mark_outside_boundary(t_data *data);
void		flood_fill(t_data *data, int y, int x);

char		*ft_strtrim_mod(char *s1, char const *set);
char		*trim_map_spaces(char *content, int min_leading_spaces);
void		skip_whitespace(char **s);
void		del(void *content);
double		get_delta_time(t_data *data);

#endif
