/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:24 by etien             #+#    #+#             */
/*   Updated: 2025/01/22 13:29:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# define WHITESPACE " \t\n"
# define MAP_ELEMENTS "01NSEW "
# define DIRECTIONS "NSEW"

// error messages
# define ARGS_ERR "Incorrect number of arguments."
# define COLOR_ERR "Invalid color."
# define EMPTY_FILE_ERR "File is empty."
# define CUB_EXTENSION_ERR "File name should end with .cub extension."
# define FILE_OPEN_ERR "File could not be opened."
# define INCOMPLETE_FIELD_ERR "Incomplete fields."
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
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_texture
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	player;
	t_texture	tex;
	int			map_height;
	int			map_width;
	char		**map;
}	t_data;

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

typedef enum e_edge_dir
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
}	t_edge_dir;

typedef struct s_vertical_neighbour
{
	bool	top;
	bool	bottom;
}	t_vertical_neighbour;

typedef struct s_horizontal_neighbour
{
	bool	left;
	bool	right;
}	t_horizontal_neighbour;

void		data_init(t_data *data);
void		img_init(t_img *img);
void		player_init(t_player *player);
void		texture_init(t_texture *texture);

void		print_map_data(t_data *data);
void		print_map(char **map);
void		print_unclosed_map(char **map, int y, int x, int edge_dir);

void		err_free_exit(char *err_msg, t_data *data, char *line);
void		free_data(t_data *data);
void		free_double_arr(char **arr);
void		tmp_exit(char *err_msg, t_data *data, t_list **tmp);

void		parse_cub(char *map_file, t_data *data);
void		parse_line(char *line, t_data *data, bool *map_detected,
				t_list **tmp);
void		parse_texture( char *s, char *line, t_data *data);
void		assign_texture(char *id, char *trimmed_path, t_data *data);
void		parse_color(char *s, char *line, t_data *data);

int			open_file(char *map_file);
bool		check_file_extension(const char *filename, const char *extension);
int			color_str_to_int(char *color_str, char *line, t_data *data);
bool		check_color_format(char **color_arr);
bool		check_completeness(t_data *data, int check_all);

void		parse_map_line(char *line, t_list **tmp);
void		parse_map(t_list **tmp, t_data *data);
void		store_map(t_list **tmp, t_data *data);
void		pad_map(t_data *data, t_list *current, int i);

bool		detect_map(t_data *data, char *line, bool *map_detected);
bool		line_is_empty(char *s);
void		remove_trailing_empty_lines(t_list *tmp);
bool		check_empty_lines(t_list *tmp);
bool		check_map_elements(char *s);

void		validate_map(t_data *data);
void		validate_player(t_data *data);
void		validate_boundaries(t_data *data);
void		validate_textures(t_data *data);

void		store_player(t_data *data, int y, int x, int *player_count);
void		store_dir_vector(t_player *player, char c);
bool		texture_is_accessible(const char *path);

bool		is_a_wall(t_data *data, int y, int x);
int			is_a_corner(t_data *data, int y, int x, int edge_dir);

bool		check_horizontal_edges(t_data *data);
bool		valid_horizontal_edge(t_data *data, int y, int x, int edge_dir);
int			get_horizontal_edge(t_data *data, int y, int x, int edge_dir);
bool		check_vertical_neighbours(t_data *data, int y, int x, int edge_dir);
void		valid_vertical_neighbours(t_data *data, int y, int x,
				t_vertical_neighbour *valid_neighbour);

bool		check_vertical_edges(t_data *data);
bool		valid_vertical_edge(t_data *data, int y, int x, int edge_dir);
int			get_vertical_edge(t_data *data, int y, int x, int edge_dir);
bool		check_horizontal_neighbours(t_data *data, int y, int x,
				int edge_dir);
void		valid_horizontal_neighbours(t_data *data, int y, int x,
				t_horizontal_neighbour *valid_neighbour);

char		*ft_strtrim_mod(char *s1, char const *set);
void		skip_whitespace(char **s);
void		del(void *content);

#endif
