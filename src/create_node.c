/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:08:43 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/26 02:46:53 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	find_redir_type(char *s)
{
	if (s[0] == '<' && s[1] == '<')
		return (4);
	else if (s[0] == '<')
		return (1);
	else if (s[0] == '>' && s[1] == '>')
		return (3);
	else
		return (2);
}

static int	find_len(char **s, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i][0] != '<' && s[i][0] != '>' && s[i][0] != '|')
	{
		len++;
		i++;
	}
	return (len);
}

t_redir	*create_redir(char **s, int *i)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->redir_type = find_redir_type(s[*i]);
	if (!s[*i + 1])
	{
		free(redir);
		return (NULL);
	}
	redir->file = ft_strdup(s[*i + 1]);
	redir->type = 3;
	*i = *i + 2;
	return (redir);
}

t_pipe	*create_pipe(int *i)
{
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->type = 2;
	*i = *i + 1;
	return (pipe);
}

t_cmd	*create_cmd(char **s, int *i)
{
	t_cmd	*cmd;
	int		len;

	cmd = malloc(sizeof(t_cmd));
	len = find_len(s, *i);
	cmd->cmd = malloc(sizeof(char *) * (len + 1));
	if (!cmd->cmd)
		return (NULL);
	len = 0;
	while (s[*i] && s[*i][0] != '<'
		&& s[*i][0] != '>' && s[*i][0] != '|')
	{
		cmd->cmd[len] = ft_strdup(s[*i]);
		len++;
		*i = *i + 1;
	}
	cmd->cmd[len] = NULL;
	cmd->type = 1;
	return (cmd);
}
