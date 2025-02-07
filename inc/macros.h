/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:52:30 by etien             #+#    #+#             */
/*   Updated: 2025/02/07 16:07:15 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1440
# define MLX_ERROR 1
# define TRUE 1
# define FALSE 0
# define PI 3.14159

// EVENT CODE
# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

// EVENT MASK
# define KEYPRESS_MASK 1
# define KEYRELEASE_MASK 2

// KEYCODES
# ifdef __APPLE__ // MacOS
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_MINUS 27
#  define KEY_PLUS 24
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_R 15
#  define KEY_I 34
#  define KEY_J 38
#  define KEY_L 37
#  define KEY_Z 6
#  define KEY_DOT 47
#  define KEY_4 21
// Reference: https://github.com/izenynn/fdf/blob/main/inc/fdf.h
# elif __linux__
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_J 106
#  define KEY_L 108
#  define KEY_P 112
#  define KEY_R 114
#  define KEY_U 117
#  define KEY_I 105
#  define KEY_K 107
#  define KEY_O 111
#  define KEY_Z 122
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_DOT 46
#  define KEY_4 52
# else
#  error Unsupported operating system
# endif

// MOUSE
# define MOUSE_CLICK 1

// COLORS
# define WHITE_PIXEL 0xFFFFFF
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define PURPLE_PIXEL 0x9900FF
# define YELLOW_PIXEL 0xFFFF00
# define ORANGE_PIXEL 0xFFA500
# define L_GREY_PIXEL 0xA1A1A1

// # define RADIAN(angle_degrees) ((angle_degrees)*PI / 180)

// Player
# define P_WIDTH 12
# define P_HEIGHT 12
# define P_MOVE_SPEED 0.1

// Wall Side
# define EW 0
# define NS 1

# define BLOCK_W 20
# define BLOCK_H 20

# define DARKEN_COLOR_MASK 0b011111110111111101111111

// DOOR
# define FULLY_OPEN 1

#endif
