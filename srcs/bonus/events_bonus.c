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
#include "../so_long_bonus.h"

void	move_player2(t_game *g, char dest, int new_y, int new_x)
{
	if (dest == 'C')
	{
		g->collectibles--;
		g->map[new_y][new_x] = '0';
	}
	if (dest == 'E' && g->collectibles == 0)
	{
		ft_printf("🎉 Victory in %d movements!\n", g->moves + 1);
		close_window(g);
	}
}

static void	move_player(t_game *g, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	dest;

	new_x = g->px + dx;
	new_y = g->py + dy;
	dest = g->map[new_y][new_x];
	if (dest == '1' || dest == 'B')
		return ;
	move_player2(g, dest, new_y, new_x);
	if (g->map[g->py][g->px] == 'P')
		g->map[g->py][g->px] = '0';
	g->px = new_x;
	g->py = new_y;
	if (g->map[g->py][g->px] != 'E')
		g->map[g->py][g->px] = 'P';
	g->moves++;
	ft_printf("🆙 Movements : %d\n", g->moves);
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
	else if (keycode == 'a' || keycode == 'A' || keycode == 65361)
	{
		g->orientation = 0;
		move_player(g, -1, 0);
	}
	else if (keycode == 'd' || keycode == 'D' || keycode == 65363)
	{
		g->orientation = 1;
		move_player(g, 1, 0);
	}
	return (0);
}

static void	destroy_images(t_game *g)
{
	int	i;

	if (g->wall.img)
		mlx_destroy_image(g->mlx, g->wall.img);
	if (g->exit.img)
		mlx_destroy_image(g->mlx, g->exit.img);
	if (g->exitMonkey.img)
		mlx_destroy_image(g->mlx, g->exitMonkey.img);
	if (g->exitMonkey1.img)
		mlx_destroy_image(g->mlx, g->exitMonkey1.img);
	if (g->ground.img)
		mlx_destroy_image(g->mlx, g->ground.img);
	if (g->player.img)
		mlx_destroy_image(g->mlx, g->player.img);
	if (g->player1.img)
		mlx_destroy_image(g->mlx, g->player1.img);
	if (g->boss.img)
		mlx_destroy_image(g->mlx, g->boss.img);
	i = 0;
	while (i < 5)
	{
		if (g->banana[i].img)
			mlx_destroy_image(g->mlx, g->banana[i].img);
		i++;
	}
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
	destroy_images(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
}

int	banana_loop(t_game *g)
{
	static long		last_time = 0;
	struct timeval	tv;
	long			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (current_time - last_time < 150)
		return (0);
	last_time = current_time;
	g->banana_frame++;
	if (g->banana_frame >= 5)
		g->banana_frame = 0;
	render_map(g);
	return (0);
}
