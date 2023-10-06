/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:24:31 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 09:27:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns 1 if the character is either
alphabeticor digit otherwise 0.
@param c: character
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) + ft_isdigit(c));
}
