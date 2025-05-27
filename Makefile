# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 13:43:11 by vloureir          #+#    #+#              #
#    Updated: 2025/05/27 11:18:34 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC := errors_and_exit.c render.c main.c libft_helpers.c fractals.c \
		colors.c data_init.c

OBJ := $(SRC:.c=.o)

HEADER := fractol.h

LIB := libmlx_Linux.a

CFLAGS := -Wall -Wextra -Werror

LFLAGS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

REPO := https://github.com/42paris/minilibx-linux.git

CC := cc

RM := rm -f

GREEN := \033[1;30;102m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $? -o $(NAME) $(CFLAGS) $(LFLAGS)
	@echo "$(GREEN)Fractol Crated"

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@ $(CFLAGS) -I.

mlx:
	git clone $(REPO)
	$(MAKE) -C ./minilibx-linux/
	@echo "$(GREEN)Minilibx Compiled"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re