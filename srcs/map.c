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

char	*append_char(char *line, char c, int len)
{
	char	*tmp;

	tmp = malloc(len + 2);
	if (!tmp)
		error("Malloc failed");
	if (line)
	{
		ft_memcpy(tmp, line, len);
		free(line);
	}
	tmp[len] = c;
	tmp[len + 1] = '\0';
	return (tmp);
}

static char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		len;
	int		ret;

	line = NULL;
	len = 0;
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n')
	{
		line = append_char(line, c, len);
		len++;
		ret = read(fd, &c, 1);
	}
	if (len == 0 && ret <= 0)
		return (NULL);
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
		error("Erreur lecture map");
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
		error("Map not found");
	read_map_lines(g, fd);
	close(fd);
	g->width = ft_strlen(g->map[0]);
}
