/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:40:52 by cfioux--          #+#    #+#             */
/*   Updated: 2026/02/03 11:33:13 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	*allocate_and_copy_line(t_game *g, char **copy, int i)
{
	char	*line;
	int		j;

	line = malloc(g->width + 1);
	if (!line)
	{
		free_copy_partial(copy, i);
		error_with_cleanup(g, "Malloc failed");
	}
	j = 0;
	while (j < g->width)
	{
		line[j] = g->map[i][j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	**copy_map(t_game *g)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (g->height + 1));
	if (!copy)
		error_with_cleanup(g, "Malloc failed");
	i = 0;
	while (i < g->height)
	{
		copy[i] = allocate_and_copy_line(g, copy, i);
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

void	flood_fill(t_game *g)
{
	char	**map_copy;

	map_copy = copy_map(g);
	fill(map_copy, g->px, g->py);
	check_flood(map_copy, g);
	free_map(map_copy, g->height);
}
