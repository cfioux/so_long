/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:38:07 by cfioux--          #+#    #+#             */
/*   Updated: 2026/02/03 11:36:23 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdarg.h>

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
	int		banana_frame;
	int		width;
	int		height;
	int		x_render;
	int 	y_render;
	int		px;
	int		py;
	int		collectibles;
	int 	count_player;
	int 	count_exit;
	int		moves;
	int		orientation;
	long    potassium_display;
	t_img	banana[5];
	t_img	wall;
	t_img	player;
	t_img	player1;
	t_img	collect;
	t_img	exit;
	t_img	exitMonkey;
	t_img	exitMonkey1;
	t_img	ground;
	t_img	boss;
}	t_game;

int		ft_printf(const char *format, ...);
int		ft_puthex_count(unsigned long n, int upper);
int		ft_putchar_count(char c);
int		ft_putstr_count(char *s);

void	init_game(t_game *g);
void	load_textures(t_game *g);

void	load_map(t_game *g, char *file);
void	check_map(t_game *g);

void	render_map(t_game *g);

int		key_press(int keycode, t_game *g);
int		close_window(t_game *g);
void	error(char *msg);
int		ft_strlen(char *s);
void	destroy_images(t_game *g);
char 	*ft_strchr(char *s, int c);

void    flood_fill(t_game *g);

int    banana_loop(t_game *g);

void	error_with_cleanup(t_game *g, char *msg);
void	free_map(char **map, int height);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	free_copy_partial(char **copy, int lines_allocated);

#endif
