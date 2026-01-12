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

#include "so_long.h"

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

void	ft_putchar(char *msg)
{
	if (msg)
	{
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
	}
	exit(1);
}
