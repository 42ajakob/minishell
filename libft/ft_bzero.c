/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:48:43 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 09:53:31 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes 'n' zeroed bytes to the string.
@param s: String
@param n: Amount of bytes to write zero.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*ls;
	size_t	i;

	ls = (char *)s;
	i = 0;
	while (i < n)
		ls[i++] = 0;
}
