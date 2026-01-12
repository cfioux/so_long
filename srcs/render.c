/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:44:24 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:44:24 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	load_textures(t_game *g)
{
	g->wall.img = mlx_xpm_file_to_image(g->mlx,
			"textures/bush.xpm", &g->wall.w, &g->wall.h);
	if (!g->wall.img)
		error("Texture bush.xpm not found");
	g->player.img = mlx_xpm_file_to_image(g->mlx,
			"textures/monkey.xpm", &g->player.w, &g->player.h);
	if (!g->player.img)
		error("Texture monkey.xpm not found");
	g->collect.img = mlx_xpm_file_to_image(g->mlx,
			"textures/bannana.xpm", &g->collect.w, &g->collect.h);
	if (!g->collect.img)
		error("Texture bannana.xpm not found");
	g->exit.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exit.xpm", &g->exit.w, &g->exit.h);
	if (!g->exit.img)
		error("Texture exit.xpm not found");
	g->ground.img = mlx_xpm_file_to_image(g->mlx,
			"textures/ground.xpm", &g->ground.w, &g->ground.h);
	if (!g->ground.img)
		error("Texture ground.xpm not found");
	g->boss.img = mlx_xpm_file_to_image(g->mlx,
			"textures/boss.xpm", &g->boss.w, &g->boss.h);
	if (!g->boss.img)
		error("Texture boss.xpm not found");
	g->exitMonkey.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exitMonkey.xpm", &g->exitMonkey.w, &g->exitMonkey.h);
	if (!g->exitMonkey.img)
		error("Texture exitMonkey.xpm not found");
}

void	render_map(t_game *g)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			mlx_put_image_to_window(g->mlx, g->win,
				g->ground.img, x * TILE, y * TILE);
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win,
					g->wall.img, x * TILE, y * TILE);
			if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win,
					g->collect.img, x * TILE, y * TILE);
			if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win,
					g->exit.img, x * TILE, y * TILE);
			if (g->px == x && g->py == y)
    			mlx_put_image_to_window(g->mlx, g->win,
					g->exitMonkey.img, x * TILE, y * TILE);
			if (g->map[y][x] == 'P')
				mlx_put_image_to_window(g->mlx, g->win,
					g->player.img, x * TILE, y * TILE);
			if (g->map[y][x] == 'B')
				mlx_put_image_to_window(g->mlx, g->win,
					g->boss.img, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}
