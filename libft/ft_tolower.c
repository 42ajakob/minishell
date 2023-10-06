/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:25:31 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 12:27:15 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Converts uppercase char to lowercase.
@param c: character
*/
int	ft_tolower(int c)
{
	unsigned int	lc;

	lc = (unsigned int)c;
	if (ft_isalpha(lc) && lc < 'a')
		return (lc + 32);
	return (lc);
}
