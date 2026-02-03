/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:43:51 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:43:51 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_images(t_game *g)
{
	if (g->wall.img)
		mlx_destroy_image(g->mlx, g->wall.img);
	if (g->exit.img)
		mlx_destroy_image(g->mlx, g->exit.img);
	if (g->exitMonkey.img)
		mlx_destroy_image(g->mlx, g->exitMonkey.img);
	if (g->ground.img)
		mlx_destroy_image(g->mlx, g->ground.img);
	if (g->player.img)
		mlx_destroy_image(g->mlx, g->player.img);
	if (g->banana.img)
		mlx_destroy_image(g->mlx, g->banana.img);
}

void	error_with_cleanup(t_game *g, char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	if (g->map)
		free_map(g->map, g->height);
	if (g->mlx)
	{
		destroy_images(g);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(1);
}

void	free_copy_partial(char **copy, int lines_allocated)
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
