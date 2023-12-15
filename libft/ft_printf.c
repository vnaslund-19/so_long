/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:10:02 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/20 16:22:56 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_upx(long num)
{
	char			*symbols;
	int				count;
	unsigned int	unum;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (num < 0)
		unum = (unsigned int)num;
	else
		unum = num;
	if (unum > 15)
	{
		count = print_upx(unum / 16);
		if (count == -1)
			return (-1);
	}
	count += print_c(symbols[unum % 16]);
	return (count);
}

int	print_u(long num)
{
	int		count;

	count = 0;
	if (num < 0)
		num = (unsigned int)num;
	if (num > 9)
	{
		count += print_i(num / 10);
		if (count == -1)
			return (-1);
	}
	count += print_c(num % 10 + 48);
	return (count);
}

int	print_p(uintptr_t num)
{
	char			*symbols;
	int				count;

	count = 0;
	symbols = "0123456789abcdef";
	if (num > 15)
	{
		count = print_p(num / 16);
		if (count == -1)
			return (-1);
	}
	else
	{
		count += write(1, "0x", 2);
		if (count == -1)
			return (-1);
	}
	count += print_c(symbols[num % 16]);
	return (count);
}

int	format_print(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_c(va_arg(args, int));
	else if (format == 's')
		count += print_s(va_arg(args, char *));
	else if (format == 'd')
		count += print_i((long)va_arg(args, int));
	else if (format == 'x')
		count += print_x((long)va_arg(args, int));
	else if (format == 'X')
		count += print_upx((long)va_arg(args, int));
	else if (format == 'i')
		count += print_i(va_arg(args, int));
	else if (format == 'u')
		count += print_u(va_arg(args, int));
	else if (format == '%')
		count += write(1, "%", 1);
	else if (format == 'p')
		count += print_p((uintptr_t)va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count += format_print(*(++format), args);
			if (count == -1)
				return (-1);
		}
		else
		{
			count += write(1, format, 1);
			if (count == -1)
				return (-1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
