/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:31:46 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/20 16:24:23 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_s(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, pft_strlen(str)));
}

int	print_i(long num)
{
	int		count;

	count = 0;
	if (num < 0)
	{
		num = -num;
		count += print_c('-');
		if (count == -1)
			return (-1);
	}
	if (num > 9)
	{
		count += print_i(num / 10);
		if (count == -1)
			return (-1);
	}
	count += print_c(num % 10 + 48);
	return (count);
}

int	print_x(long num)
{
	char			*symbols;
	int				count;
	unsigned int	unum;

	count = 0;
	symbols = "0123456789abcdef";
	if (num < 0)
		unum = (unsigned long)num;
	else
		unum = num;
	if (unum > 15)
	{
		count = print_x(unum / 16);
		if (count == -1)
			return (-1);
	}
	count += print_c(symbols[unum % 16]);
	return (count);
}
