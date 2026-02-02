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
	g->player1.img = mlx_xpm_file_to_image(g->mlx,
			"textures/monkey1.xpm", &g->player1.w, &g->player1.h);
	g->banana[0].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana.xpm", &g->banana[0].w, &g->banana[0].h);
	g->banana[1].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana1.xpm", &g->banana[1].w, &g->banana[1].h);
	g->banana[2].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana2.xpm", &g->banana[2].w, &g->banana[2].h);
	g->banana[3].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana3.xpm", &g->banana[3].w, &g->banana[3].h);
	g->banana[4].img = mlx_xpm_file_to_image(g->mlx,
			"textures/banana/banana4.xpm", &g->banana[4].w, &g->banana[4].h);
	g->banana_frame = 0;
}

void	load_textures(t_game *g)
{
	g->wall.img = mlx_xpm_file_to_image(g->mlx,
			"textures/bush.xpm", &g->wall.w, &g->wall.h);
	g->exit.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exit.xpm", &g->exit.w, &g->exit.h);
	g->exitMonkey.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exitMonkey.xpm", &g->exitMonkey.w, &g->exitMonkey.h);
	g->exitMonkey1.img = mlx_xpm_file_to_image(g->mlx,
			"textures/exitMonkey1.xpm", &g->exitMonkey1.w, &g->exitMonkey1.h);
	g->ground.img = mlx_xpm_file_to_image(g->mlx,
			"textures/ground.xpm", &g->ground.w, &g->ground.h);
	g->boss.img = mlx_xpm_file_to_image(g->mlx,
			"textures/boss.xpm", &g->boss.w, &g->boss.h);
	load_textures2(g);
}

void	render_map2(t_game *g)
{
	if (g->px == g->x_render && g->py == g->y_render)
	{
		if (g->orientation == 0)
			mlx_put_image_to_window(g->mlx, g->win,
				g->exitMonkey.img, g->x_render * TILE, g->y_render * TILE);
		else
			mlx_put_image_to_window(g->mlx, g->win,
				g->exitMonkey1.img, g->x_render * TILE, g->y_render * TILE);
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
