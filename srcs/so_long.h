/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:38:07 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/15 16:44:17 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
#include <sys/time.h>

# define TILE 64

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		px;
	int		py;
	int		collectibles;
	int		moves;
	int		orientation;
	t_img	wall;
	t_img	player;
	t_img	player1;
	t_img	collect;
	t_img	exit;
	t_img	ground;
	t_img	boss;
}	t_game;

void	init_game(t_game *g);
void	load_textures(t_game *g);

void	load_map(t_game *g, char *file);
void	check_map(t_game *g);

void	render_map(t_game *g);

int		key_press(int keycode, t_game *g);
int		close_window(t_game *g);

void	error(char *msg);
int		ft_strlen(char *s);
long int get_time_second();

char *ft_strchr(char *s, int c);

void    flood_fill(t_game *g);

#endif

