# NAME = cub3D

# SRC = \
# main.c

# OBJ = $(SRC:.c=.o)

# LIBFT_DIR = libft/
# LIBFT = $(LIBFT_DIR)libft.a

# CC = cc -g
# CFLAGS = -Wall -Wextra -Werror -Iinclude
# RM = rm -f

# all: $(NAME)

# $(NAME): $(OBJ) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LFLAG)

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	@make -C $(LIBFT_DIR)

# clean:
# 	@make clean -C $(LIBFT_DIR)
# 	@$(RM) $(OBJ)

# fclean: clean
# 	@make fclean -C $(LIBFT_DIR)
# 	@$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) #-fsanitize=address -g #-std=c99
INCLUDES = -Iinc -I$(LIBFT_DIR) 
# Output executable
NAME = cub3d 

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m

# Source files
SRCDIR = src/

SRCS_FIL = \
			main.c
			\

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

# Object files
OBJDIR = objs/
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

# Libraries
LIBFT_DIR = libft/
LIBFT_A = $(LIBFT_DIR)libft.a


UNAME := $(shell uname)


# Build targets
all: $(OBJDIR) $(NAME)

bonus: all

$(OBJDIR):
	@mkdir -p $(OBJDIR) $(addprefix $(OBJDIR), $(dir $(SRCS_FIL)))

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(LIBFT_A) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft && echo "$(GREEN)$(NAME) was created$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "$(GREEN)object files were created$(RESET)"

# Cleanup
RM = rm -rf

clean:
	@$(RM) $(OBJDIR) && echo "$(ORANGE)object files were deleted$(RESET)"
	@make clean -C $(LIBFT_DIR) && echo "$(ORANGE)libft object files were deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME) && echo "$(ORANGE)$(NAME) was deleted$(RESET)"
	@make fclean -C $(LIBFT_DIR) && echo "$(ORANGE)libft.a was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus