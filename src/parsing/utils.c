/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:46:05 by etien             #+#    #+#             */
/*   Updated: 2025/02/06 19:15:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// A wrapper function for ft_strtrim to free the input string.
char	*ft_strtrim_mod(char *s1, char const *set)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	free(s1);
	return (trimmed_str);
}

// This helper function is called in parse_map to trim leading and trailing
// spaces in the map lines while preserving their alignment.
char	*trim_map_spaces(char *content, int min_leading_spaces)
{
	char	*trimmed_content;
	size_t	len;

	if (!content)
		return (NULL);
	len = ft_strlen(content);
	while (len > 0 && content[len - 1] == ' ')
		len--;
	if (min_leading_spaces == 0 && (len == ft_strlen(content)))
		return (content);
	trimmed_content = ft_substr(content, min_leading_spaces,
			len - min_leading_spaces);
	free(content);
	return (trimmed_content);
}

// A helper function for skipping over leading whitespace.
void	skip_whitespace(char **s)
{
	while (**s && ft_strchr(WHITESPACE, **s))
		(*s)++;
}

// The content deletion function for clearing a t_list.
void	del(void *content)
{
	free(content);
}

// This function will return the time difference between frames to
// increment door_progress and animate the sliding movement of the door.
double	get_delta_time(t_data	*data)
{
	struct timeval	current_time;
	double			delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - data->last_time.tv_sec)
		+ (current_time.tv_usec - data->last_time.tv_usec) / 1e6;
	data->last_time = current_time;
	return (delta_time);
}
