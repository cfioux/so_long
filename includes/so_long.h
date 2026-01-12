/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:38:07 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:38:12 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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
	t_img	wall;
	t_img	player;
	t_img	collect;
	t_img	exit;
	t_img	ground;
}	t_game;

/* init */
void	init_game(t_game *g);
void	load_textures(t_game *g);

/* map */
void	load_map(t_game *g, char *file);
void	check_map(t_game *g);

/* render */
void	render_map(t_game *g);

/* events */
int		key_press(int keycode, t_game *g);
int		close_window(t_game *g);

/* utils */
void	error(char *msg);
int		ft_strlen(char *s);

#endif
