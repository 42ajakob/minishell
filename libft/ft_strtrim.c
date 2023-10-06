/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:03:58 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/11 10:53:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_be_trimmed(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/*
Returns the first index from s1 that is not trimmed.
*/
static size_t	strim_left(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (to_be_trimmed(s1[start], set))
		start++;
	return (start);
}

/*
Returns the last index from s1 that is not trimmed.
*/
static size_t	strim_right(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (to_be_trimmed(s1[end], set))
		end--;
	return (end);
}

/*
Retruns a trimmed string. NULL if allocation fails.
@param s1: string to be trimmed.
@param set: characters to trim.
*/
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	start = strim_left(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = strim_right(s1, set);
	len = end - start + 1;
	new = ft_substr(s1, start, len);
	return (new);
}
