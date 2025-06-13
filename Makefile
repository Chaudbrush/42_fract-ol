# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 13:43:11 by vloureir          #+#    #+#              #
#    Updated: 2025/06/13 11:18:35 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC := src/errors_and_exit.c src/render.c src/main.c src/libft_helpers.c \
		src/fractals.c src/colors.c src/data_init.c src/parsing.c

OBJ := $(SRC:.c=.o)

HEADER := includes/fractol.h

INC := -I includes

LIB := libmlx_Linux.a

CFLAGS := -Wall -Wextra -Werror

LFLAGS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

REPO := https://github.com/42paris/minilibx-linux.git

MLX_DIR := ./minilibx-linux/

CC := cc

RM := rm -f

RED := \033[1;30;41m

GREEN := \033[1;30;42m

OFF := \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN) Minilibx Compiled $(OFF)"
	$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME) $(INC)
	@echo "$(GREEN) Fractol Crated $(OFF)"

mlx:
	git clone $(REPO)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED) Executable Deleted $(OFF)"

re: fclean all

del: fclean
	rm -rf $(MLX_DIR)
	@echo "$(RED) Minilibx Deleted $(OFF)"

.PHONY: all clean fclean re del mlx