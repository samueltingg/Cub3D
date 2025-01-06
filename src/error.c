/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:54:26 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 15:55:01 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will print out the error message to STDERR
// and exit the program.
void	err_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(1);
}
