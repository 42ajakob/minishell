/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:53:55 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/12 13:52:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n /= 16;
	return (len);
}

/*
@set-param arg: Type of hex, uppercase X or lowercase x.
*/
static void	print_hex(unsigned int n, int arg, int fd)
{
	char	hex_base[16];

	if (arg == 1)
		ft_strlcpy(hex_base, "0123456789abcdef", 17);
	else if (arg == 0)
		ft_strlcpy(hex_base, "0123456789ABCDEF", 17);
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 16)
		ft_putchar_fd(hex_base[n % 16], fd);
	else
	{
		ft_puthex_fd(n / 16, arg, fd);
		ft_putchar_fd(hex_base[n % 16], fd);
	}
}

int	ft_puthex_fd(unsigned int n, int arg, int fd)
{
	print_hex(n, arg, fd);
	return (get_len(n));
}
