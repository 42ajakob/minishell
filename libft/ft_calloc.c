/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:22:42 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/11 23:12:43 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates enought space for count objects that are size bytes each
and returns a pointer to the allocated memory. The allocated memory is
filled with bytes of value 0.
@param count: amount of data types to store.
@param size: size in bytes of each data type.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count * size) > INT_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
