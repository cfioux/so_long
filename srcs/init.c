/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:44:05 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:44:05 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game_basic(t_game *g)
{
	g->moves = 0;
	g->collectibles = 0;
	g->count_exit = 0;
	g->count_player = 0;
	g->height = 0;
	g->map = NULL;
	g->mlx = NULL;
	g->win = NULL;
	g->wall.img = NULL;
	g->exit.img = NULL;
	g->exitMonkey.img = NULL;
	g->ground.img = NULL;
	g->player.img = NULL;
	g->banana.img = NULL;
}

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		free_map(g->map, g->height);
		error("MLX init failed");
	}
}
