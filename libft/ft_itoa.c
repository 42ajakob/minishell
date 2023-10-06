/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:27:11 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/05 16:38:12 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	abs_val(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

/*
Returns a string representing the integer received.
*/
char	*ft_itoa(int n)
{
	char	*new;
	size_t	len;

	len = number_len(n);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[len--] = '\0';
	if (n == 0)
		new[0] = '0';
	if (n < 0)
		new[0] = '-';
	while (n)
	{
		new[len--] = abs_val(n % 10) + '0';
		n = n / 10;
	}
	return (new);
}
