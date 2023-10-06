/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:42:34 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/11 10:57:17 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns a substring from ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
@param s: string
@param start: start index
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	int		max;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	max = slen - start;
	if (slen < start)
		len = 0;
	if ((size_t)max > len)
		max = len;
	res = malloc((max + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_memmove(res, s + start, max);
	res[max] = '\0';
	return (res);
}
