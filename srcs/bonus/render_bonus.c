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

#include "../so_long_bonus.h"

void	load_textures2(t_game *g)
{
	g->player.img = mlx_xpm_file_to_image(g->mlx,
			"textures/monkey.xpm", &g->player.w, &g->player.h);
	if (!g->player.img)
		error("player.xpm not found", 1, g);
	g->player1.img = mlx_xpm_file_to_image(g->mlx,
			"textures/monkey1.xpm", &g->player1.w, &g->player1.h);
	if (!g->player1.img)
		error("player1.xpm not found", 1, g);
	g->banana[0].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana.xpm", &g->banana[0].w, &g->banana[0].h);
	if (!g->banana[0].img)
		error("banana.xpm not found", 1, g);
	g->banana[1].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana1.xpm", &g->banana[1].w, &g->banana[1].h);
	if (!g->banana[1].img)
		error("banana1.xpm not found", 1, g);
	g->banana[2].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana2.xpm", &g->banana[2].w, &g->banana[2].h);
	if (!g->banana[2].img)
		error("banana2.xpm not found", 1, g);
	g->banana[3].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana3.xpm", &g->banana[3].w, &g->banana[3].h);
	if (!g->banana[3].img)
		error("banana3.xpm not found", 1, g);
}

void	load_texture3(t_game *g)
{
	g->banana[4].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana4.xpm", &g->banana[4].w, &g->banana[4].h);
	if (!g->banana[4].img)
		error("banana4.xpm not found", 1, g);
	g->banana_frame = 0;
}

void	load_textures(t_game *g)
{
	g->wall.img = mlx_xpm_file_to_image(g->mlx,
			"textures/bush.xpm", &g->wall.w, &g->wall.h);
	if (!g->wall.img)
		error("bush.xpm not found", 1, g);
	g->exit.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exit.xpm", &g->exit.w, &g->exit.h);
	if (!g->exit.img)
		error("exit.xpm not found", 1, g);
	g->exitmonkey.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exitmonkey.xpm", &g->exitmonkey.w, &g->exitmonkey.h);
	if (!g->exitmonkey.img)
		error("exitmonkey.xpm not found", 1, g);
	g->exitmonkey1.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exitmonkey1.xpm", &g->exitmonkey1.w, &g->exitmonkey1.h);
	if (!g->exitmonkey1.img)
		error("exitmonkey1.xpm not found", 1, g);
	g->ground.img = mlx_xpm_file_to_image(g->mlx,
			"textures/ground.xpm", &g->ground.w, &g->ground.h);
	if (!g->ground.img)
		error("ground.xpm not found", 1, g);
	load_textures2(g);
	load_texture3(g);
}

void	render_map2(t_game *g)
{
	if (g->px == g->x_render && g->py == g->y_render)
	{
		if (g->orientation == 0)
			mlx_put_image_to_window(g->mlx, g->win,
				g->exitmonkey.img, g->x_render * TILE, g->y_render * TILE);
		else
			mlx_put_image_to_window(g->mlx, g->win,
				g->exitmonkey1.img, g->x_render * TILE, g->y_render * TILE);
	}
	if (g->map[g->y_render][g->x_render] == 'P')
	{
		if (g->orientation == 0)
			mlx_put_image_to_window(g->mlx, g->win,
				g->player.img, g->x_render * TILE, g->y_render * TILE);
		else
			mlx_put_image_to_window(g->mlx, g->win,
				g->player1.img, g->x_render * TILE, g->y_render * TILE);
	}
	if (g->map[g->y_render][g->x_render] == 'B')
		mlx_put_image_to_window(g->mlx, g->win,
			g->boss.img, g->x_render * TILE, g->y_render * TILE);
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
			if (g->map[g->y_render][g->x_render] == '1')
				mlx_put_image_to_window(g->mlx, g->win,
					g->wall.img, g->x_render * TILE, g->y_render * TILE);
			if (g->map[g->y_render][g->x_render] == 'C')
			{
				mlx_put_image_to_window(g->mlx, g->win,
					g->banana[g->banana_frame].img,
					g->x_render * TILE, g->y_render * TILE);
			}
			if (g->map[g->y_render][g->x_render] == 'E')
				mlx_put_image_to_window(g->mlx, g->win,
					g->exit.img, g->x_render * TILE, g->y_render * TILE);
			render_map2(g);
			g->x_render++;
		}
		g->y_render++;
	}
}
