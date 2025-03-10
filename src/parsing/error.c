/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:54:26 by etien             #+#    #+#             */
/*   Updated: 2025/01/24 16:23:05 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will print out the error message to STDERR,
// free dynamically-allocated memory and exit the program.
void	err_free_exit(char *err_msg, t_data *data, char *line)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (data)
		free_data(data);
	if (line)
		free(line);
	exit(1);
}

// This function frees the data struct.
// Other than floor_color and ceiling_color, all the other data fields
// are dynamically-allocated.
void	free_data(t_data *data)
{
	if (data->tex.path[0])
		free(data->tex.path[0]);
	if (data->tex.path[1])
		free(data->tex.path[1]);
	if (data->tex.path[2])
		free(data->tex.path[2]);
	if (data->tex.path[3])
		free(data->tex.path[3]);
	if (data->map)
		free_double_arr(data->map);
}

// A helper function to free double arrays.
void	free_double_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

// This is a modified version of err_free_exit.
// It will free both the temporary linked list and
// the data struct.
void	tmp_exit(char *err_msg, t_data *data, t_list **tmp)
{
	ft_lstclear(tmp, del);
	err_free_exit(err_msg, data, NULL);
}
