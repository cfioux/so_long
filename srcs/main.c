/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:44:09 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/05 09:44:09 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		error("Usage: ./so_long map.ber");
	init_game(&g);
	load_map(&g, av[1]);
	check_map(&g);
	flood_fill(&g);
	g.win = mlx_new_window(g.mlx, g.width * TILE,
			g.height * TILE, "so_long");
	load_textures(&g);
	render_map(&g);
	mlx_key_hook(g.win, key_press, &g);
	mlx_hook(g.win, 17, 0, close_window, &g);
	mlx_loop(g.mlx);
}