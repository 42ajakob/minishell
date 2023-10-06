/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:46:10 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/26 20:21:18 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	returns length of str for allocation
*/
static int	str_len(char *s, int i)
{
	if (s[i] == '"')
	{
		i++;
		while (s[i] && s[i] != '"')
			i++;
		if (s[i])
			i++;
	}
	else if (s[i] == '\'')
	{
		i++;
		while (s[i] && s[i] != '\'')
			i++;
		if (s[i])
			i++;
	}
	else
		while (s[i] && s[i] != ' ' && s[i] != '|' && s[i] != '<'
			&& s[i] != '>' && s[i] != '\'' && s[i] != '"')
				i++;
	if (s[i] && (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>'))
			i = str_len(s, i);
	return (i);
}

/*
	Checks if it is cmd, pipe or redir and returns it's length
*/
static int	check_type(char *s, int i)
{
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] && s[i] == '|')
		i++;
	else if (s[i] && (s[i] == '<' || s[i] == '>'))
	{
		i++;
		while ((s[i] == '<') || (s[i] == '>'))
			i++;
	}
	else
		i = str_len(s, i);
	return (i);
}

/*
	returns number of substrings to allocate
*/
static int	num_of_substr(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (!s[i])
		return (0);
	i = 0;
	while (s[i])
	{
		i = check_type(s, i);
		while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			i++;
		j++;
	}
	return (j);
}

/*
	Creates substring and returns it
*/
static char	*substr(char *s, int i)
{
	char	*substr;
	int		j;
	int		k;
	int		start;
	int		end;

	j = 0;
	k = 0;
	while (k < i)
	{
		j = check_type(s, j);
		while (s[j] && (s[j] == ' ' || (s[j] >= 9 && s[j] <= 13)))
			j++;
		k++;
	}
	while (s[j] && (s[j] == ' ' || (s[j] >= 9 && s[j] <= 13)))
		j++;
	start = j;
	end = check_type(s, j);
	substr = ft_calloc(sizeof(char), (end - start + 1));
	if (!substr)
		return (NULL);
	substr[end - start] = '\0';
	ft_strlcpy(substr, &s[start], end - start + 1);
	return (substr);
}

/*
	Splitting char *input to char **tokens
*/
char	**mini_split(char *s)
{
	char	**str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = num_of_substr(s);
	if (len == 0)
		return (NULL);
	str = ft_calloc(sizeof(char *), (len + 1));
	if (!str)
		return (NULL);
	str[len] = NULL;
	while (i < len)
	{
		str[i] = substr(s, i);
		if (!str[i])
			return (free_split(str), NULL);
		i++;
	}
	return (str);
}
