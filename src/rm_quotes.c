/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 05:10:17 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/23 07:43:56 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*rm_char(char *str, int i)
{
	char	*before;
	char	*after;

	before = ft_substr(str, 0, i);
	after = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	str = ft_strjoin(before, after);
	free(before);
	free(after);
	return (str);
}

static char	*check_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
		{
			s = rm_char(s, i);
			while (s[i] != '\"')
				i++;
			s = rm_char(s, i);
		}
		else if (s[i] == '\'')
		{
			s = rm_char(s, i);
			while (s[i] != '\'')
				i++;
			s = rm_char(s, i);
		}
		else
			i++;
	}
	return (s);
}

/*
	Removes quotes from tokens
*/
void	rm_quotes(t_list *tokens)
{
	t_list	*tmp;
	char	*s;
	int		i;

	tmp = tokens;
	while (tmp)
	{
		if (((t_cmd *)tmp->content)->type == 1)
		{
			i = 0;
			while (((t_cmd *)tmp->content)->cmd[i])
			{
				s = check_quotes(((t_cmd *)tmp->content)->cmd[i]);
				((t_cmd *)tmp->content)->cmd[i++] = s;
			}
		}
		else if (((t_redir *)tmp->content)->type == 3)
		{
			s = check_quotes(((t_redir *)tmp->content)->file);
			((t_redir *)tmp->content)->file = s;
		}
		tmp = tmp->next;
	}
}
