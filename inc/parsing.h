/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:24 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 15:55:59 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# define WHITESPACE " \t"

// error messages
# define ARGS_ERR "Error: Incorrect number of arguments."
# define EXTENSION_ERR "Error: File name should end with .cub extension."
# define FILE_OPEN_ERR "Error: File could not be opened."
# define MAP_MALLOC_ERR "Error: Map malloc failure."
# define TEXTURE_PATH_ERR "Error: No texture path."

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	char	**grid;
}	t_map;

void	err_and_exit(char *err_msg);

t_map	*map_init(void);

void	parse_map(char *map_file, t_map *map);
void	parse_line(char *line, t_map *map);
void	store_texture( char *s, t_map *map);
bool	check_file_extension(const char *filename);

#endif
