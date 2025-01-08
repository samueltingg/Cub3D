/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:24 by etien             #+#    #+#             */
/*   Updated: 2025/01/08 15:52:17 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# define WHITESPACE " \t\n"
# define MAP_ELEMENTS "01NSEW"

// error messages
# define ARGS_ERR "Error: Incorrect number of arguments."
# define COLOR_ERR "Error: Invalid color."
# define MAP_LINE_ERR "Error: Map should not contain empty lines."
# define MAP_ORDER_ERR "Error: Map should be the last element."
# define EXTENSION_ERR "Error: File name should end with .cub extension."
# define FILE_OPEN_ERR "Error: File could not be opened."
# define INCOMPLETE_FIELD_ERR "Error: Incomplete field."
# define MAP_MALLOC_ERR "Error: Map malloc failure."

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

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
}	t_map;

void	err_free_exit(char *err_msg, t_map *map, char *line);
void	free_map(t_map *map);
void	free_double_arr(char **arr);

t_map	*map_init(void);

void	parse_cub_file(char *map_file, t_map *map);
void	parse_line(char *line, t_map *map, bool *map_detected, t_list **tmp);
void	parse_texture( char *s, t_map *map);
void	parse_color(char *s, char *line, t_map *map);
bool	check_file_extension(const char *filename);
int		color_str_to_int(char *color_str, char *line, t_map *map);
bool	check_color_format(char **color_arr);
bool	check_completeness(t_map *map, int check_all);

void	parse_map_line(char *line, t_list **tmp, t_map *map);
void	parse_map(t_list **tmp, t_map *map);

bool	detect_map(char *line, bool *map_detected);
bool	line_is_empty(char *s);
void	remove_trailing_empty_lines(t_list **tmp);

char	*ft_strtrim_mod(char *s1, char const *set);
void	skip_characters(char *characters, char **s);

#endif
