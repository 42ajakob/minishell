/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/12 13:17:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n /= 16;
	return (len);
}

static void	put_hex_fd(unsigned long long n, int fd)
{
	char	hex_base[16];

	ft_strlcpy(hex_base, "0123456789abcdef", 17);
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 16)
		ft_putchar_fd(hex_base[n % 16], fd);
	else
	{
		put_hex_fd(n / 16, fd);
		ft_putchar_fd(hex_base[n % 16], fd);
	}
}

int	ft_putaddr_fd(unsigned long long addr, int fd)
{
	ft_putstr_fd("0x", fd);
	put_hex_fd(addr, fd);
	return (get_len(addr) + 2);
}
