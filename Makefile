# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 09:44:33 by cfioux--          #+#    #+#              #
#    Updated: 2026/03/20 21:31:11 by cfioux--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
LIB = minilibx-linux
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
LIB_MINI = $(MLX_DIR)
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
	srcs/utils.c \
	srcs/ft_printf/ft_printf.c \
	srcs/ft_printf/ft_printf_utils.c \
	srcs/ft_printf/ft_puthex_count.c

SRCS_BONUS = srcs/bonus/error_bonus.c \
		srcs/bonus/events_bonus.c \
		srcs/bonus/flood_fill_bonus.c \
		srcs/bonus/init_bonus.c \
		srcs/bonus/main_bonus.c \
		srcs/bonus/map_bonus.c \
		srcs/bonus/map_check_bonus.c \
		srcs/bonus/render_bonus.c \
		srcs/bonus/utils_bonus.c \
		srcs/ft_printf/ft_printf.c \
		srcs/ft_printf/ft_printf_utils.c \
		srcs/ft_printf/ft_puthex_count.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = -I includes -I $(MLX_DIR) -I./

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

all: $(LIB_MINI) $(NAME)

	@echo "$(IRed)                  $(White)__                         "
	@echo "$(IBlue)  __________$(White)     |  |   ____  $(IRed) ____    ____  "
	@echo "$(IBlue) /  ___/  _ \ $(White)   |  |  /  _ \ $(IRed)/    \  / ___\ "
	@echo "$(IBlue) \___ (  <_> )$(White)   |  | (  <_> $(IRed))   |  \/ /_/  >"
	@echo "$(IBlue) \___ (  <_> )$(White)   |  |_(  <_> $(IRed))   |  \/ /_/  >"
	@echo "$(IBlue)/____  >____/$(White)____|____/\____/$(IRed)|___|  /\___  / "
	@echo "$(IBlue)     \/    $(White)/_____/           $(IRed)     \//_____/  "

bonus: $(LIB_MINI) $(NAME_BONUS)
	@echo "$(IRed)                  __                           "
	@echo "$(IBlue)  __________$(IRed)     |  |   ____   ____    ____     $(Yellow)___.                               "
	@echo "$(IBlue) /  ___/  _ \ $(IRed)   |  |  /  _ \ /    \  / ___\    $(Yellow)\_ |__   ____   ____  __ __  ______"
	@echo "$(IBlue) \___ (  <_> )$(IRed)   |  |_(  <_> )   |  \/ /_/  >   $(Yellow)| __ \ /  _ \ /    \|  |  \/  ___/"
	@echo "$(IBlue) \___ (  <_> )$(IRed)   |  |_(  <_> )   |  \/ /_/  >   $(Yellow)| \_\ (  <_> )   |  \  |  /\___ \ "
	@echo "$(IBlue)/____  >____/$(White)____$(IRed)|____/\____/|___|  /\___  /    $(Yellow)|___  /\____/|___|  /____//____ >"
	@echo "$(IBlue)     \/    $(White)/_____/$(IRed)                \//_____/     "

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -g $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -g $(OBJS_BONUS) $(INCLUDES) $(LIBS) -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) compiled successfully!"

$(LIB_MINI):
	@git clone https://github.com/42Paris/minilibx-linux --depth=1
	@make --no-print-directory -C $(MLX_DIR) -j
	@echo "Importation of MiniLibX finished!"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "Object files cleaned!"

fclean: clean
	@rm -rf $(LIB)
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "Executables removed!"

re: fclean all
re_bonus: fclean bonus

.PHONY: all bonus clean fclean re