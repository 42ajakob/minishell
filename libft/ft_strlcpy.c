/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:13 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 15:22:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies up to 'dstsize - 1" characters from src into dst
and guarnatees NUL-termination if is room. Room for null
should be included in dstsize.
@param src: destinaton string
@param dst: src string
@param dstsize: destination size.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	slen = -1;
	while (src[++slen])
		;
	if (dstsize == 0)
		return (slen);
	i = -1;
	while (src[++i] && i < dstsize - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (slen);
}
