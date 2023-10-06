/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:16:00 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/06 18:42:37 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares at most n characters from two
null-terminated strings s1 & s2. Characters
that appear after \0 are not compared.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ls1;
	unsigned char	*ls2;

	ls1 = (unsigned char *)s1;
	ls2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ls1[i] && ls2[i] && ls1[i] == ls2[i] && i < n - 1)
		i++;
	return (ls1[i] - ls2[i]);
}
