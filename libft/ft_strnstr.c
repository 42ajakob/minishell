/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:18:23 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/11 12:21:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurence of the null-terminated string needle
in the first n bytes from the string haystack. Characters after
\0 are not searched
@param haystack: string
@param needle: substring
@param len: bytes
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && i < ft_strlen(haystack))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (j == 0)
				ptr = (char *)(haystack + i + j);
			j++;
			if (j == ft_strlen(needle))
				return (ptr);
		}
		i++;
	}
	return (NULL);
}
