NAME = cub3D

SRC = \
main.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -Iinclude
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LFLAG)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
