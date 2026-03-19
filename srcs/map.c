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

#include "../so_long.h"

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

static char	*read_line(int fd, int i)
{
	char	c;
	char	*line;
	int		ret;

	line = NULL;
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
	if (ret <= 0)
		free(line);
	if (ret <= 0)
		return (NULL);
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
	int		*buff;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Map not found", 0, NULL);
	count = 0;
	line = read_line(fd, 0);
	if (read(fd, &buff, 0) == -1)
	{
		close(fd);
		error("Map not can be a directory", 0, NULL);
	}
	while (line)
	{
		free(line);
		count++;
		line = read_line(fd, 0);
	}
	close(fd);
	if (count == 0)
		error("Map vide", 0, NULL);
	return (count);
}

static void	read_map_lines(t_game *g, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = read_line(fd, 0);
	while (i < g->height && line)
	{
		g->map[i] = line;
		i++;
		line = read_line(fd, 0);
	}
	g->map[i] = NULL;
	if (i == 0)
	{
		close(fd);
		free_map(g->map, g->height);
		error("Erreur lecture map", 0, NULL);
	}
}

void	load_map(t_game *g, char *file)
{
	int		fd;

	g->height = count_lines(file);
	g->map = malloc(sizeof(char *) * (g->height + 1));
	if (!g->map)
		error("Malloc failed", 0, NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error("Map not found", 0, NULL);
	}
	read_map_lines(g, fd);
	close(fd);
	g->width = ft_strlen(g->map[0]);
}
