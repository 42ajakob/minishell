/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:29:00 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 09:32:33 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns 1 if the character is ascii otherwise 0
@param c: character
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
