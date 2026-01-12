# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 09:44:33 by cfioux--          #+#    #+#              #
#    Updated: 2026/01/05 09:44:33 by cfioux--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux

SRCS = srcs/*.c

INCLUDES = -Iincludes -I$(MLX_DIR)

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME):
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
