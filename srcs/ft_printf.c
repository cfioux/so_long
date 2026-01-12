/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfioux-- <cfioux--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:35:13 by cfioux--          #+#    #+#             */
/*   Updated: 2026/01/12 13:17:53 by cfioux--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_count(long n)
{
	char	buf[20];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (ft_putchar_count('0'));
	if (n < 0)
	{
		len += ft_putchar_count('-');
		n = -n;
	}
	while (n)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (--i >= 0)
		len += ft_putchar_count(buf[i]);
	return (len);
}

static int	ft_putunsigned_count(unsigned long n)
{
	char	buf[20];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (ft_putchar_count('0'));
	while (n)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (--i >= 0)
		len += ft_putchar_count(buf[i]);
	return (len);
}

static int	ft_putptr_count(void *p)
{
	unsigned long	addr;
	int				len;

	if (!p)
		return (ft_putstr_count("(nil)"));
	addr = (unsigned long)p;
	len = write(1, "0x", 2);
	len += ft_puthex_count(addr, 0);
	return (len);
}

static int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_count((char)va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_count((long)va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsigned_count((unsigned long)
				va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex_count((unsigned long)va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex_count((unsigned long)va_arg(args, unsigned int), 1));
	if (c == 'p')
		return (ft_putptr_count(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar_count('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		ret;

	total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			ret = ft_handle_format(*format, args);
			if (ret == -1)
				return (va_end(args), -1);
			total += ret;
		}
		else
			total += ft_putchar_count(*format);
		format++;
	}
	va_end(args);
	return (total);
}
