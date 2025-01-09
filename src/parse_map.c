/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/09 15:25:27 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function stores extracted map lines in a temporary linked list.
// line[ft_strlen(line) - 1] = 0 changes the newline character
// to a null terminator.
void	parse_map_line(char *line, t_list **tmp, t_map *map)
{
	t_list	*node;

	if (!check_completeness(map, MAP_IS_LAST))
		err_free_exit(MAP_ORDER_ERR, map, line);
	line[ft_strlen(line) - 1] = 0;
	node = malloc(sizeof(t_list));
	node->content = ft_strdup(line);
	node->next = NULL;
	ft_lstadd_back(tmp, node);
}

// This function will parse the temporary linked list before
// creating the 2D array for the map.
// The workflow is:
// - remove trailing empty lines from the linked list
// - check that the linked list does not have empty lines in between
// - extract map height
// - extract map width
// - iterate through each line and check for invalid map elements
void	parse_map(t_list **tmp, t_map *map)
{
	t_list	*current;
	int		max_width;

	remove_trailing_empty_lines(*tmp);
	if (check_empty_lines(*tmp))
		tmp_exit(MAP_EMPTY_LINE_ERR, map, tmp);
	map->map_height = ft_lstsize(*tmp);
	current = *tmp;
	max_width = -1;
	while (current)
	{
		if (!check_map_elements(current->content))
			tmp_exit(MAP_ELEMENT_ERR, map, tmp);
		if ((int)ft_strlen(current->content) > max_width)
			max_width = (int)ft_strlen(current->content);
		current = current->next;
	}
	map->map_width = max_width;
	store_map(tmp, map);
}

// This function will malloc a 2D array to store the map from
// the temporary linked list, then free the linked list.
void	store_map(t_list **tmp, t_map *map)
{
	t_list	*current;
	int		y;

	current = *tmp;
	map->map = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->map)
		tmp_exit(MAP_ARR_MALLOC_ERR, map, tmp);
	map->map[map->map_height] = 0;
	y = -1;
	while (current)
	{
		map->map[++y] = malloc(sizeof(char) * (map->map_width + 1));
		if (!map->map[y])
			tmp_exit(MAP_ARR_MALLOC_ERR, map, tmp);
		map->map[y][map->map_width] = 0;
		strcpy(map->map[y], current->content);
		pad_map(map, current, y);
		current = current->next;
	}
	ft_lstclear(tmp, del);
}

// This function will pad the map so that all rows have equal width.
void	pad_map(t_map *map, t_list *current, int y)
{
	int	len;
	int	padding_width;

	len = (int)ft_strlen(current->content);
	padding_width = map->map_width - len;
	while (padding_width > 0)
	{
		map->map[y][len] = ' ';
		len++;
		padding_width--;
	}
}
