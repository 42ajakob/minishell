/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:52:51 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/12 13:38:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs c to the given file descriptor.
@param c: character
@param fd: file descriptor
*/
int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
