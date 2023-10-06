/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:54:08 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 10:08:08 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Copies 'n' bytes from src to dst. If src & dst overlap
the behavior is undefined.
@param src: source memory address.
@param dst: destination memory address.
@param n: Quantity of bytes.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ldst;
	char	*lsrc;
	size_t	i;

	if (!src && !dst)
		return (NULL);
	ldst = (char *)dst;
	lsrc = (char *)src;
	i = -1;
	while (++i < n)
		ldst[i] = lsrc[i];
	return (dst);
}
