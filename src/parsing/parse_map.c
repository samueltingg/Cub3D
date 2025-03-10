/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:29 by etien             #+#    #+#             */
/*   Updated: 2025/02/07 16:14:08 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function stores extracted map lines in a temporary linked list.
// line[ft_strlen(line) - 1] = 0 changes the newline character
// to a null terminator.
void	parse_map_line(char *line, t_list **tmp)
{
	t_list	*node;

	if (line[ft_strlen(line) - 1] == '\n')
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
// - check that the linked list does not have invalid map elements
// - extract map height
// - trim leading and trailing spaces in the map lines
// - extract map width
void	parse_map(t_list **tmp, t_data *data)
{
	t_list	*current;
	int		max_width;
	int		min_leading_spaces;

	remove_trailing_empty_lines(*tmp);
	if (check_empty_lines(*tmp))
		tmp_exit(MAP_EMPTY_LINE_ERR, data, tmp);
	if (!check_map_elements(*tmp))
		tmp_exit(MAP_ELEMENT_ERR, data, tmp);
	data->map_height = ft_lstsize(*tmp);
	min_leading_spaces = get_min_leading_spaces(*tmp);
	current = *tmp;
	max_width = -1;
	while (current)
	{
		current->content = trim_map_spaces(current->content,
				min_leading_spaces);
		if ((int)ft_strlen(current->content) > max_width)
			max_width = (int)ft_strlen(current->content);
		current = current->next;
	}
	data->map_width = max_width;
	store_map(tmp, data);
}

// This function will return the minimum leading spaces after checking
// through all the map lines in the linked list so that all lines can
// have their leading whitespace trimmed uniformly.
int	get_min_leading_spaces(t_list *current)
{
	int		min_leading_spaces;
	int		leading_spaces;
	char	*line_content;

	min_leading_spaces = -1;
	while (current)
	{
		leading_spaces = 0;
		line_content = (char *)current->content;
		while (line_content[leading_spaces] == ' ')
			leading_spaces++;
		if (min_leading_spaces == -1 || leading_spaces < min_leading_spaces)
			min_leading_spaces = leading_spaces;
		current = current->next;
	}
	return (min_leading_spaces);
}

// This function will malloc a 2D array to store the map from
// the temporary linked list, then free the linked list.
void	store_map(t_list **tmp, t_data *data)
{
	t_list	*current;
	int		y;

	current = *tmp;
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		tmp_exit(MAP_ARR_MALLOC_ERR, data, tmp);
	data->map[data->map_height] = 0;
	y = -1;
	while (current)
	{
		data->map[++y] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->map[y])
			tmp_exit(MAP_ARR_MALLOC_ERR, data, tmp);
		data->map[y][data->map_width] = 0;
		ft_strlcpy(data->map[y], current->content,
			ft_strlen(current->content) + 1);
		pad_map(data, current, y);
		current = current->next;
	}
	ft_lstclear(tmp, del);
}

// This function will pad the map so that all rows have equal width.
void	pad_map(t_data *data, t_list *current, int y)
{
	int	len;
	int	padding_width;

	len = (int)ft_strlen(current->content);
	padding_width = data->map_width - len;
	while (padding_width > 0)
	{
		data->map[y][len] = ' ';
		len++;
		padding_width--;
	}
}
