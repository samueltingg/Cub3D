#ifndef MACROS_H
# define MACROS_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR 1
# define TRUE 1
# define FALSE 0
# define PI 3.14159

// EVENT CODES
# define ON_KEYDOWN 2 // mac only :()
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

// Linux KEYCODES
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

// COLORS
# define WHITE_PIXEL 0xFFFFFF
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define PURPLE_PIXEL 0x9900FF
# define YELLOW_PIXEL 0xFFFFCC
# define ORANGE_PIXEL 0xFFA500

# define RADIAN(angle_degrees) ((angle_degrees)*PI / 180)
# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((r) << 16) + ((g) << 8) + (b)

#endif