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

#include "so_long.h"

static char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		ret;

	line = malloc(1000);
	if (!line)
		return (NULL);
	i = 0;
	while ((ret = read(fd, &c, 1)) == 1)
	{
		if (c == '\n')
			break ;
		if (i >= 999)
			error("Ligne trop longue");
		line[i++] = c;
	}
	line[i] = '\0';
	if (i == 0 && ret == 0)
	{
		free(line);
		return (NULL);
	}
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
	while ((line = read_line(fd)))
	{
		free(line);
		count++;
	}
	close(fd);
	if (count == 0)
		error("Map vide");
	return (count);
}

void	load_map(t_game *g, char *file)
{
	int		fd;
	int		i;
	char	*line;

	g->height = count_lines(file);
	g->map = malloc(sizeof(char *) * (g->height + 1));
	if (!g->map)
		error("Malloc failed");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Map not found");
	i = 0;
	while (i < g->height && (line = read_line(fd)))
	{
		g->map[i] = line;
		i++;
	}
	g->map[i] = NULL;
	close(fd);
	if (i == 0)
		error("Erreur lecture map");
	g->width = ft_strlen(g->map[0]);
}