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
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
IRed = \033[0;31m
IBlue = \033[1;94m
White = \033[0;37m
Yellow=\033[0;93m

SRCS = srcs/error.c \
	srcs/events.c \
	srcs/flood_fill.c \
	srcs/init.c \
	srcs/main.c \
	srcs/map.c \
	srcs/map_check.c \
	srcs/render.c \
	srcs/utils.c

SRCS_BONUS = bonus/error_bonus.c \
		bonus/events_bonus.c \
		bonus/flood_fill_bonus.c \
		bonus/init_bonus.c \
		bonus/main_bonus.c \
		bonus/map_bonus.c \
		bonus/map_check_bonus.c \
		bonus/render_bonus.c \
		bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = -Iincludes -I$(MLX_DIR)

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

	@echo "$(IRed)                  __                         "
	@echo "$(IBlue)  __________$(IRed)     |  |   ____   ____    ____  "
	@echo "$(IBlue) /  ___/  _ \ $(IRed)   |  |  /  _ \ /    \  / ___\ "
	@echo "$(IBlue) \___ (  <_> )$(IRed)   |  |_(  <_> )   |  \/ /_/  >"
	@echo "$(IBlue) \___ (  <_> )$(IRed)   |  |_(  <_> )   |  \/ /_/  >"
	@echo "$(IBlue)/____  >____/$(White)____$(IRed)|____/\____/|___|  /\___  / "
	@echo "$(IBlue)     \/    $(White)/_____/$(IRed)                \//_____/  "

bonus: $(NAME_BONUS)
	@echo "$(IRed)                  __                           "
	@echo "$(IBlue)  __________$(IRed)     |  |   ____   ____    ____     $(Yellow)___.                               "
	@echo "$(IBlue) /  ___/  _ \ $(IRed)   |  |  /  _ \ /    \  / ___\    $(Yellow)\_ |__   ____   ____  __ __  ______"
	@echo "$(IBlue) \___ (  <_> )$(IRed)   |  |_(  <_> )   |  \/ /_/  >   $(Yellow)| __ \ /  _ \ /    \|  |  \/  ___/"
	@echo "$(IBlue) \___ (  <_> )$(IRed)   |  |_(  <_> )   |  \/ /_/  >   $(Yellow)| \_\ (  <_> )   |  \  |  /\___ \ "
	@echo "$(IBlue)/____  >____/$(White)____$(IRed)|____/\____/|___|  /\___  /    $(Yellow)|___  /\____/|___|  /____//____ >"
	@echo "$(IBlue)     \/    $(White)/_____/$(IRed)                \//_____/     "

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES) $(LIBS) -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling $<"

clean:
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "Object files cleaned!"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "Executables removed!"

re: fclean all

.PHONY: all bonus clean fclean re
