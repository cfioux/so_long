/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:21:52 by cfioux--          #+#    #+#             */
/*   Updated: 2025/11/06 14:46:03 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_base(char *base, int upper)
{
	int	i;

	i = 0;
	if (upper)
	{
		while (i < 16)
		{
			base[i] = "0123456789ABCDEF"[i];
			i++;
		}
	}
	else
	{
		while (i < 16)
		{
			base[i] = "0123456789abcdef"[i];
			i++;
		}
	}
}

static int	convert_to_hex(unsigned long n, char *base, char *buf)
{
	int	i;

	i = 0;
	while (n)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	return (i);
}

static int	print_hex_buffer(char *buf, int len)
{
	int	i;
	int	count;

	i = len - 1;
	count = 0;
	while (i >= 0)
		count += ft_putchar_count(buf[i--]);
	return (count);
}

int	ft_puthex_count(unsigned long n, int upper)
{
	char	base[16];
	char	buf[32];
	int		len;

	init_base(base, upper);
	if (n == 0)
		return (ft_putchar_count('0'));
	len = convert_to_hex(n, base, buf);
	return (print_hex_buffer(buf, len));
}
