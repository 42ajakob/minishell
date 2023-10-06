/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:40:19 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/09 09:50:50 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns 1 if the character is alphabetic otherwise 0
@param c: character
*/
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z')))
		return (1);
	return (0);
}
