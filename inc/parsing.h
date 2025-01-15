/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:24 by etien             #+#    #+#             */
/*   Updated: 2025/01/15 20:49:25 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# define WHITESPACE " \t\n"
# define MAP_ELEMENTS "01NSEW "
# define DIRECTIONS "NSEW"

// error messages
# define ARGS_ERR "Error: Incorrect number of arguments."
# define COLOR_ERR "Error: Invalid color."
# define EXTENSION_ERR "Error: File name should end with .cub extension."
# define FILE_OPEN_ERR "Error: File could not be opened."
# define INCOMPLETE_FIELD_ERR "Error: Incomplete field."
# define MAP_ARR_MALLOC_ERR "Error: Map array malloc failure."
# define MAP_EMPTY_LINE_ERR "Error: Map should not contain empty lines."
# define MAP_ELEMENT_ERR "Error: Invalid map element."
# define MAP_MALLOC_ERR "Error: Map struct malloc failure."
# define MAP_ORDER_ERR "Error: Map should be the last element."
# define MAP_BOUNDARIES_ERR "Error: Map boundaries are unclosed."
# define PLAYER_COUNT_ERR "Error: Only one player is allowed."
# define PLAYER_MISSING_ERR "Error: No player found in the map."

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

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	int		map_height;
	int		map_width;
	char	**map;
	int		player_dir;
	int		player_x;
	int		player_y;
}	t_map;

void	print_map_data(t_map *map);
void	print_map(t_map *map);
void	print_unclosed_map(t_map *map, int y, int x, int edge_dir);

void	err_free_exit(char *err_msg, t_map *map, char *line);
void	free_map(t_map *map);
void	free_double_arr(char **arr);
void	tmp_exit(char *err_msg, t_map *map, t_list **tmp);

t_map	*map_init(void);

void	parse_cub(char *map_file, t_map *map);
void	parse_line(char *line, t_map *map, bool *map_detected, t_list **tmp);
void	parse_texture( char *s, t_map *map);
void	parse_color(char *s, char *line, t_map *map);

bool	check_file_extension(const char *filename);
int		color_str_to_int(char *color_str, char *line, t_map *map);
bool	check_color_format(char **color_arr);
bool	check_completeness(t_map *map, int check_all);

void	parse_map_line(char *line, t_list **tmp, t_map *map);
void	parse_map(t_list **tmp, t_map *map);
void	store_map(t_list **tmp, t_map *map);
void	pad_map(t_map *map, t_list *current, int i);

bool	detect_map(char *line, bool *map_detected);
bool	line_is_empty(char *s);
void	remove_trailing_empty_lines(t_list *tmp);
bool	check_empty_lines(t_list *tmp);
bool	check_map_elements(char *s);

void	validate_map(t_map *map);
void	validate_player(t_map *map);
void	store_player(t_map *map, int y, int x);
void	validate_boundaries(t_map *map);

bool	is_a_wall(t_map *map, int y, int x);
int		is_a_corner(t_map *map, int y, int x, int edge_dir);

bool	check_horizontal_edges(t_map *map);
bool	valid_horizontal_edge(t_map *map, int y, int x, int edge_dir);
int		get_horizontal_edge(t_map *map, int y, int x, int edge_dir);
bool	check_vertical_neighbours(t_map *map, int y, int x, int edge_dir);
void	valid_vertical_neighbours(t_map *map, int y, int x,
			t_vertical_neighbour *valid_neighbour);

bool	check_vertical_edges(t_map *map);
bool	valid_vertical_edge(t_map *map, int y, int x, int edge_dir);
int		get_vertical_edge(t_map *map, int y, int x, int edge_dir);
bool	check_horizontal_neighbours(t_map *map, int y, int x, int edge_dir);
void	valid_horizontal_neighbours(t_map *map, int y, int x,
			t_horizontal_neighbour *valid_neighbour);

char	*ft_strtrim_mod(char *s1, char const *set);
void	skip_whitespace(char **s);
void	del(void *content);

#endif
