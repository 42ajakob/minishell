/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:32:17 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 18:40:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns a copy of a string.
*/
char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	cpy = ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	i = -1;
	while (++i < len)
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}
