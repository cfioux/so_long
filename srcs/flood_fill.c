/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:40:52 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/27 09:52:52 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_copy_partial(char **copy, int lines_allocated)
{
	int	i;

	i = 0;
	while (i < lines_allocated)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

static char	**copy_map(t_game *g)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc(sizeof(char *) * (g->height + 1));
	if (!copy)
		error_with_cleanup(g, "Malloc failed");
	i = 0;
	while (i < g->height)
	{
		copy[i] = malloc(g->width + 1);
		if (!copy[i])
		{
			free_copy_partial(copy, i);
			error_with_cleanup(g, "Malloc failed");
		}
		j = 0;
		while (j < g->width)
		{
			copy[i][j] = g->map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

static void	check_flood(char **map, t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				free_map(map, g->height);
				error_with_cleanup(g, "Map no playable (flood fill)");
			}
			x++;
		}
		y++;
	}
}

static void	free_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	flood_fill(t_game *g)
{
	char	**map_copy;

	map_copy = copy_map(g);
	fill(map_copy, g->px, g->py);
	check_flood(map_copy, g);
	free_copy(map_copy, g->height);
}
