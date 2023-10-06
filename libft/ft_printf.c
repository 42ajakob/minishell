/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:10:20 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/12 13:54:00 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_param(int fd, char format_specifier, va_list args)
{
	if (format_specifier == '%')
		return (ft_putchar_fd('%', fd));
	if (format_specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (format_specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (format_specifier == 'd' || format_specifier == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (format_specifier == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(args, unsigned int), fd));
	if (format_specifier == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), 1, fd));
	if (format_specifier == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), 0, fd));
	if (format_specifier == 'p')
		return (ft_putaddr_fd(va_arg(args, unsigned long long), fd));
	return (0);
}

int	ft_printf(int fd, const char *text, ...)
{
	va_list	args;
	int		printed_bytes;

	printed_bytes = 0;
	va_start(args, text);
	while (*text)
	{
		if (*text != '%')
		{
			write(fd, text, 1);
			printed_bytes++;
		}
		else
		{
			printed_bytes += get_param(fd, *(text + 1), args);
			text++;
		}
		text++;
	}
	va_end(args);
	return (printed_bytes);
}
