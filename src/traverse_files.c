/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:28:08 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 03:50:38 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Allocates memory for the traverser
and initializes it with the next values:
int		fd[2]: fd[0] input, fd[1] output
*/
t_traverser	*init_traverser(int *fd)
{
	t_traverser	*out;

	out = (t_traverser *)malloc(sizeof(t_traverser));
	if (!out)
		return (NULL);
	out->fd = fd;
	out->pipe = NULL;
	out->cmd = NULL;
	return (out);
}

void	close_previous_fd(int *fd, int redir_type)
{
	if (redir_type == 1 && fd[0] > 0)
		close(fd[0]);
	else if ((redir_type == 2 || redir_type == 3) && fd[1] > 1)
		close(fd[1]);
}

/*
Returns -1 if fails otherwise 0.
*/
int	open_new_fd(int *fd, char *filename, int redir_type)
{
	if (redir_type == 1 || redir_type == 4)
	{
		fd[0] = open(filename, O_RDONLY);
		if (fd[0] < 0)
			return (-2);
	}
	else if (redir_type == 2)
	{
		fd[1] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd[1] < 0)
			return (cmd_unknown("couldn't create the file", filename), -1);
	}
	else if (redir_type == 3)
	{
		fd[1] = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd[1] < 0)
			return (cmd_unknown("couldn't create the file", filename), -1);
	}
	return (0);
}

int	init_type(t_list *tmp, t_traverser *out, int *fd)
{
	t_redir		*token;

	token = (t_redir *)tmp->content;
	if (token->type == 3)
	{
		close_previous_fd(fd, token->redir_type);
		if (open_new_fd(fd, token->file, token->redir_type) == -1)
		{
			set_fds(fd, 0);
			return (1);
		}
		else if (open_new_fd(fd, token->file, token->redir_type) == -2)
		{
			cmd_unknown("no such file or directory", token->file);
			set_fds(fd, 1);
		}
	}
	else if (token->type == 1)
		out->cmd = ((t_cmd *)tmp->content)->cmd;
	else if (token->type == 2)
	{
		out->pipe = tmp;
		return (1);
	}
	return (0);
}

/*
Goes through the command until finds a pipe or
the end of line. And opens the corrects file descriptors for
stdin and stdout substitution.
* fd[0] is the input
* fd[1] is the output
*/
t_traverser	*traverse_files(t_list *tokens)
{
	t_traverser	*out;
	t_list		*tmp;
	int			*fd;

	if (!tokens)
		return (NULL);
	fd = ft_calloc(2, sizeof(int));
	if (!fd)
		return (NULL);
	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	out = init_traverser(fd);
	if (!out)
		return (free(fd), NULL);
	tmp = tokens;
	while (tmp)
	{
		if (init_type(tmp, out, fd))
			return (out);
		tmp = tmp->next;
	}
	return (out);
}
