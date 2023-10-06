/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:56:24 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/06 18:33:47 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compare byte string s1 with s2. Both are supposed to be
n bytes long.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ls1;
	unsigned char	*ls2;
	size_t			i;

	ls1 = (unsigned char *)s1;
	ls2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && ls1[i] == ls2[i])
		i++;
	return (ls1[i] - ls2[i]);
}
