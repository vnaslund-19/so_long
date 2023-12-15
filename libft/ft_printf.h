/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:55:01 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/20 13:56:04 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	pft_strlen(const char *str);
int	ft_printf(const char *format, ...);
int	format_print(char format, va_list args);
int	print_p(uintptr_t num);
int	print_u(long num);
int	print_upx(long num);
int	print_x(long num);
int	print_i(long num);
int	print_s(char *str);
int	print_c(int c);

#endif
