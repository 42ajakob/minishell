/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:18:38 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 12:24:52 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Converts lowercase char to uppercase.
@param c: character
*/
int	ft_toupper(int c)
{
	unsigned int	lc;

	lc = (unsigned int)c;
	if (ft_isalpha(lc) && lc >= 'a')
		return (lc - 32);
	return (lc);
}
