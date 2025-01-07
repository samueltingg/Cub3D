/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:24 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 11:43:43 by etien            ###   ########.fr       */
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
# define INCOMPLETE_DATA_ERR " Error: Incomplete data."
# define MAP_MALLOC_ERR "Error: Map malloc failure."
# define TEXTURE_PATH_ERR "Error: Invalid texture path."

typedef enum
{
	NORTH,
	SOUTH,
	WEST,
	EAST
} t_direction;

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map;
}	t_map;

void	err_and_exit(char *err_msg);
void	free_map(t_map *map);
void	free_double_arr(char **arr);

t_map	*map_init(void);

void	parse_cub_file(char *map_file, t_map *map);
void	parse_line(char *line, t_map *map);
void	parse_texture( char *s, t_map *map);
void	parse_color(char *s, t_map *map);
bool	check_file_extension(const char *filename);
void	color_str_to_int(char *color_str, int *color_int);
bool	check_color_format(char **color_arr);
bool	detect_map(char *line);
bool	check_completeness(t_map *map, int check_all);

char	*ft_strtrim_mod(char *s1, char const *set);
void	skip_characters(char *characters, char **s);

#endif
