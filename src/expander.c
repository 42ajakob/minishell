/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:54:11 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/24 04:59:00 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	skip_quotes(char *str, int i, char quotes)
{
	i++;
	while (str[i] != quotes)
	{
		if (quotes == '\"' && str[i] == '$' && str[i + 1]
			&& ((ft_isalnum(str[i + 1]) || str[i + 1] == '_')
				|| str[i + 1] == '?' || str[i + 1] == '$'))
			return (i);
		else
			i++;
	}
	i++;
	return (i);
}

/*
	Quotes handeling
	Returns variable
*/
static char	*check_for_quotes(char *s, t_list *env, int exit_status)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			i = skip_quotes(s, i, '\"');
		else if (s[i] == '\'')
			i = skip_quotes(s, i, '\'');
		else if (s[i] == '$' && s[i + 1]
			&& ((ft_isalnum(s[i + 1]) || s[i + 1] == '_')
				|| s[i + 1] == '?' || s[i + 1] == '$'))
		{
			s = conv_to_env_var(s, env, exit_status, i);
			if (!s)
				return (NULL);
			i = 0;
		}
		else
			i++;
	}
	return (s);
}

/*
	Checks for t_cmd or t_redir in tokens. Then replaces $ with var.
*/
void	expander(t_list *tokens, t_list *env, int e_s)
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
				s = check_for_quotes(((t_cmd *)tmp->content)->cmd[i], env, e_s);
				((t_cmd *)tmp->content)->cmd[i++] = s;
			}
		}
		else if (((t_redir *)tmp->content)->type == 3)
		{
			s = check_for_quotes(((t_redir *)tmp->content)->file, env, e_s);
			((t_redir *)tmp->content)->file = s;
		}
		tmp = tmp->next;
	}
	rm_quotes(tokens);
}
