/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:44:12 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:44:12 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_chars(t_game *g, int *p, int *e)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (!ft_strchr("01CEP", g->map[y][x]))
				error("charactor invalide in the map");
			if (g->map[y][x] == 'P')
			{
				g->px = x;
				g->py = y;
				(*p)++;
			}
			if (g->map[y][x] == 'C')
				g->collectibles++;
			if (g->map[y][x] == 'E')
				(*e)++;
			x++;
		}
		y++;
	}
}

static void	check_walls(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->width)
	{
		if (g->map[0][i] != '1'
			|| g->map[g->height - 1][i] != '1')
			error("map not closed by walls");
		i++;
	}
	i = 0;
	while (i < g->height)
	{
		if (g->map[i][0] != '1'
			|| g->map[i][g->width - 1] != '1')
			error("map not closed by walls");
		i++;
	}
}

static void	check_rectangle(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->height)
	{
		if ((int)ft_strlen(g->map[i]) != g->width)
			error("map is not a rectangle");
		i++;
	}
}

void	check_map(t_game *g)
{
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	check_rectangle(g);
	check_walls(g);
	check_chars(g, &player, &exit);
	if (player != 1)
		error("no player detected");
	if (exit < 1)
		error("no exit detected");
	if (g->collectibles < 1)
		error("no coin detected");
}
