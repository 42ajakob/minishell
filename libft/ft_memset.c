/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:40:39 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 12:31:37 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Writes len bytes of value c (converted to an unsigned char) to the string b.
@param b: string (If NULL seg fault)
@param c: character
@param len: bytes to write the character to the string.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	char	*ls;
	size_t	i;

	ls = (char *)b;
	i = 0;
	while (i < len)
		ls[i++] = (unsigned char)c;
	return (ls);
}
