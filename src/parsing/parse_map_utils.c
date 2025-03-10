/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:26 by etien             #+#    #+#             */
/*   Updated: 2025/02/06 18:05:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will detect for the map by skipping over
// whitespace and checking that the first character is one
// of the map elements. It will also toggle the map_detected
// boolean when the map is detected.
bool	detect_map(t_data *data, char *line, bool *map_detected)
{
	char	*s;

	s = line;
	if (!check_completeness(data, MAP_IS_LAST))
		err_free_exit(MAP_ORDER_ERR, data, line);
	skip_whitespace(&s);
	if (ft_strchr(MAP_ELEMENTS, *s))
	{
		*map_detected = true;
		return (true);
	}
	else
		return (false);
}

// This function will return true if a line is empty,
// i.e. composed entirely of whitespace.
bool	line_is_empty(char *s)
{
	while (*s)
	{
		if (!ft_strchr(WHITESPACE, *s))
			return (false);
		s++;
	}
	return (true);
}

// This function will trim trailing empty lines from
// the temporary linked list by marking where the last
// non-empty line is and freeing all subsequent lines.
void	remove_trailing_empty_lines(t_list *tmp)
{
	t_list	*current;
	t_list	*last_non_empty;
	t_list	*previous;

	current = tmp;
	last_non_empty = NULL;
	previous = NULL;
	while (current)
	{
		if (!line_is_empty(current->content))
			last_non_empty = current;
		current = current->next;
	}
	if (!last_non_empty->next)
		return ;
	current = last_non_empty->next;
	last_non_empty->next = NULL;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous->content);
		free(previous);
	}
}

// This function traverses the temporary linked list and checks that
// there are no empty lines in the middle of the map.
bool	check_empty_lines(t_list *tmp)
{
	t_list	*current;

	current = tmp;
	while (current)
	{
		if (line_is_empty(current->content))
			return (true);
		current = current->next;
	}
	return (false);
}

// This function will check that all the map elements in the
// linked list are valid.
bool	check_map_elements(t_list *tmp)
{
	t_list	*current;
	char	*s;

	current = tmp;
	while (current)
	{
		s = current->content;
		while (*s)
		{
			if (!ft_strchr(MAP_ELEMENTS, *s))
				return (false);
			s++;
		}
		current = current->next;
	}
	return (true);
}
