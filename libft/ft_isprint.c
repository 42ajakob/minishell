/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:33:54 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 09:34:57 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns 1 if the character is printable otherwise 0
@param c: character
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
