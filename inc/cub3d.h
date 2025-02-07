/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:35:23 by sting             #+#    #+#             */
/*   Updated: 2025/02/07 09:06:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft/libft.h"
# include "execution.h"
# include "macros.h"
# ifdef __APPLE__
#  include "../minilibx/minilibx-macOS/mlx.h"
# elif __linux__
#  include "../minilibx/minilibx-linux/mlx.h"
# else
#  error Unsupported operating system
# endif
# include "parsing.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

#endif
