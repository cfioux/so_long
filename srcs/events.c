/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:43:56 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:43:56 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = g->px + dx;
	new_y = g->py + dy;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'B')
		return ;
	if (g->map[new_y][new_x] == 'C')
	{
		g->collectibles--;
		g->map[new_y][new_x] = '0';
	}
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collectibles == 0)
		{
			printf("🎉 Victory in %d moovements !\n", g->moves + 1);
			close_window(g);
		}
		return ;
	}
	g->map[g->py][g->px] = '0';
	g->px = new_x;
	g->py = new_y;
	g->map[g->py][g->px] = 'P';
	g->moves++;
	printf("🆙 Movements : %d\n", g->moves);
	render_map(g);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == 65307)
		close_window(g);
	else if (keycode == 'w' || keycode == 'W' || keycode == 65362)
		move_player(g, 0, -1);
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		move_player(g, 0, 1);
	else if (keycode == 'a' || keycode == 'A'|| keycode == 65361)
	{
		g->orientation = 0;
		move_player(g, -1, 0);
	}
	else if (keycode == 'd' || keycode == 'D'|| keycode == 65363)
	{
		g->orientation = 1;
		move_player(g, 1, 0);
	}
	return (0);
}

int	close_window(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->height)
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}
