/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:44:21 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:44:21 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	*grow_line(char *line, int size)
{
	char	*new;

	new = malloc(size + 1);
	if (!new)
		return (NULL);
	if (line)
	{
		ft_memcpy(new, line, size);
		free(line);
	}
	return (new);
}

static char	*read_line(int fd)
{
	char	c;
	char	*line;
	int		i;
	int		ret;

	line = NULL;
	i = 0;
	ret = read(fd, &c, 1);
	while (ret == 1)
	{
		if (c == '\n')
			break ;
		line = grow_line(line, i);
		if (!line)
			return (NULL);
		line[i++] = c;
		ret = read(fd, &c, 1);
	}
	if (i == 0 && ret == 0)
		return (free(line), NULL);
	line = grow_line(line, i);
	if (!line)
		return (NULL);
	line[i] = '\0';
	return (line);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Map not found");
	count = 0;
	line = read_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = read_line(fd);
	}
	close(fd);
	if (count == 0)
		error("Map vide");
	return (count);
}

static void	read_map_lines(t_game *g, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = read_line(fd);
	while (i < g->height && line)
	{
		g->map[i] = line;
		i++;
		line = read_line(fd);
	}
	g->map[i] = NULL;
	if (i == 0)
	{
		close(fd);
		free_map(g->map, g->height);
		error("Erreur lecture map");
	}
}

void	load_map(t_game *g, char *file)
{
	int		fd;

	g->height = count_lines(file);
	g->map = malloc(sizeof(char *) * (g->height + 1));
	if (!g->map)
		error("Malloc failed");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error("Map not found");
	}
	read_map_lines(g, fd);
	close(fd);
	g->width = ft_strlen(g->map[0]);
}
