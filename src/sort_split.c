/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:19:55 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/24 02:24:04 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	cmd_into_str(char **str, char **s, int i, int *j)
{
	while (s[i])
	{
		if (s[i][0] == '<' || s[i][0] == '>')
		{
			if (s[i + 1])
				i = i + 2;
			else
				i++;
		}
		else if (s[i][0] == '|')
		{
			i++;
			break ;
		}
		else
		{
			str[*j] = ft_strdup(s[i]);
			*j = *j + 1;
			i++;
		}
	}
	return (i);
}

static int	redir_pipe_into_str(char **str, char **s, int i, int *j)
{
	while (s[i])
	{
		if (s[i][0] == '<' || s[i][0] == '>')
		{
			str[*j] = ft_strdup(s[i++]);
			*j = *j + 1;
			if (s[i])
			{
				str[*j] = ft_strdup(s[i++]);
				*j = *j + 1;
			}
		}
		else if (s[i][0] == '|')
		{
			str[*j] = ft_strdup(s[i++]);
			*j = *j + 1;
			break ;
		}
		else
			i++;
	}
	return (i);
}

char	**sort_split(char **s)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
		i++;
	str = ft_calloc(sizeof(char *), (i + 1));
	if (!str)
		return (free_split(s), NULL);
	str[i] = NULL;
	i = 0;
	while (s[i])
	{
		i = cmd_into_str(str, s, i, &j);
		i = 0 + k;
		i = redir_pipe_into_str(str, s, i, &j);
		if (s[i])
			k = i;
	}
	free_split(s);
	return (str);
}
