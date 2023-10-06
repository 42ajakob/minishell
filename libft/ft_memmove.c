/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:08:59 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 10:32:22 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies 'len' bytes from src to destination. 
The copy is done in a non-destructive manner.
@param src: source memory address.
@param dst: destination memory address.
@param n: Quantity of bytes.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ldst;
	unsigned char	*lsrc;

	if ((!dst && !src))
		return (NULL);
	ldst = (unsigned char *)dst;
	lsrc = (unsigned char *)src;
	if (ldst > lsrc)
	{
		while (len--)
			ldst[len] = lsrc[len];
	}
	else
		ft_memcpy(ldst, lsrc, len);
	return (ldst);
}
