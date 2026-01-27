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

#include "../so_long_bonus.h"

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		error("MLX init failed");
	g->moves = 0;
	g->collectibles = 0;
	g->orientation = 0;
	g->potassium_display = 0;
	g->map = NULL;
	g->win = NULL;
	g->wall.img = NULL;
	g->exit.img = NULL;
	g->exitMonkey.img = NULL;
	g->exitMonkey1.img = NULL;
	g->ground.img = NULL;
	g->player.img = NULL;
	g->player1.img = NULL;
	g->banana[0].img = NULL;
	g->banana[1].img = NULL;
	g->banana[2].img = NULL;
	g->banana[3].img = NULL;
	g->banana[4].img = NULL;
}
