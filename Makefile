# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -fsanitize=address -g #-std=c99
INCLUDES = -Iinc -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# Output executable
NAME = cub3D

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m

# Source files
SRCDIR = src/

SRCS_FIL = \
			main.c \
			execution/bresenham.c \
			execution/render.c \
			execution/handle_key_event.c \
			execution/raycasting.c \
			execution/render_minimap.c \
			execution/textures.c \
			execution/img_pix_put.c \
			execution/movement.c \
			$(addprefix parsing/, \
			error.c init.c  \
			parse_cub_utils.c parse_cub.c \
			parse_map_utils.c parse_map.c \
			print.c utils.c \
			validate_map_horizontal.c validate_map_utils.c validate_map_vertical.c validate_map.c)

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

# Object files
OBJDIR = objs/
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

# Libraries
LIBFT_DIR = libft/
LIBFT_A = $(LIBFT_DIR)libft.a


# MINILIBX_DIR = minilibx-linux/
# LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# Set MINILIBX_DIR based on the operating system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)  # macOS
    MINILIBX_DIR = minilibx/minilibx-macOS/
	LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
else ifeq ($(UNAME_S), Linux)  # Linux
    MINILIBX_DIR = minilibx/minilibx-linux/
	LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else
    $(error Unsupported operating system)
endif

# Build targets
all: $(OBJDIR) $(NAME)

bonus: all

$(OBJDIR):
	@mkdir -p $(OBJDIR) $(addprefix $(OBJDIR), $(dir $(SRCS_FIL)))

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MINILIBX_DIR)
	@$(CC) $(LIBFT_A) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES) && echo "$(GREEN)$(NAME) was created$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "$(GREEN)object files were created$(RESET)"

# Cleanup
RM = rm -rf

clean:
	@$(RM) $(OBJDIR) && echo "$(ORANGE)object files were deleted$(RESET)"
	@make clean -C $(LIBFT_DIR) && echo "$(ORANGE)libft object files were deleted$(RESET)"
	@make clean -C $(MINILIBX_DIR) && echo "$(ORANGE)ran make clean in $(MINILIBX_DIR)$(RESET)"

fclean: clean
	@$(RM) $(NAME) && echo "$(ORANGE)$(NAME) was deleted$(RESET)"
	@make fclean -C $(LIBFT_DIR) && echo "$(ORANGE)libft.a was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
