/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/05 18:09:17 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	len(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	indexof(char *s1, char c)
{
	int	i;

	if (!s1)
		return (-2);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*j_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	ls1;
	size_t	ls2;
	int		i;
	int		j;

	ls1 = len(s1);
	ls2 = len(s2);
	new = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}

char	*j_substr(char *s1, size_t start, size_t end)
{
	char	*new;
	size_t	ls1;
	size_t	new_len;
	size_t	i;

	ls1 = len(s1);
	new_len = ls1 - start;
	new = malloc((new_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[start + i] && i < end)
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
