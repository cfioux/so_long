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

#include "../so_long.h"

void	load_textures(t_game *g)
{
	g->wall.img = mlx_xpm_file_to_image(g->mlx,
			"textures/bush.xpm", &g->wall.w, &g->wall.h);
	if (!g->wall.img)
		error("Texture bush.xpm not found", 1, g);
	g->exit.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exit.xpm", &g->exit.w, &g->exit.h);
	if (!g->exit.img)
		error("Texture exit.xpm not found", 1, g);
	g->exitmonkey.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exitmonkey.xpm", &g->exitmonkey.w, &g->exitmonkey.h);
	if (!g->exitmonkey.img)
		error("Texture exitmonkey.xpm not found", 1, g);
	g->ground.img = mlx_xpm_file_to_image(g->mlx,
			"textures/ground.xpm", &g->ground.w, &g->ground.h);
	if (!g->ground.img)
		error("Texture ground.xpm not found", 1, g);
	g->player.img = mlx_xpm_file_to_image(g->mlx,
			"textures/monkey.xpm", &g->player.w, &g->player.h);
	if (!g->player.img)
		error("Texture player.xpm not found", 1, g);
	g->banana.img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana.xpm", &g->banana.w, &g->banana.h);
	if (!g->banana.img)
		error("Texture banana.xpm not found", 1, g);
}

static void	render_tile(t_game *g)
{
	if (g->map[g->y_render][g->x_render] == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->wall.img, g->x_render * TILE, g->y_render * TILE);
	if (g->map[g->y_render][g->x_render] == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->banana.img, g->x_render * TILE, g->y_render * TILE);
	if (g->map[g->y_render][g->x_render] == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->exit.img, g->x_render * TILE, g->y_render * TILE);
	if (g->px == g->x_render && g->py == g->y_render)
		mlx_put_image_to_window(g->mlx, g->win,
			g->exitmonkey.img, g->x_render * TILE, g->y_render * TILE);
	if (g->map[g->y_render][g->x_render] == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->player.img, g->x_render * TILE, g->y_render * TILE);
}

void	render_map(t_game *g)
{
	g->y_render = 0;
	while (g->y_render < g->height)
	{
		g->x_render = 0;
		while (g->x_render < g->width)
		{
			mlx_put_image_to_window(g->mlx, g->win,
				g->ground.img, g->x_render * TILE, g->y_render * TILE);
			render_tile(g);
			g->x_render++;
		}
		g->y_render++;
	}
}
