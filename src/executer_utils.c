/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 01:41:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 01:47:04 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_redir(t_traverser *tmp)
{
	if (tmp->fd[0] != 0)
	{
		dup2(tmp->fd[0], STDIN_FILENO);
		close(tmp->fd[0]);
	}
	if (tmp->fd[1] != 1)
	{
		dup2(tmp->fd[1], STDOUT_FILENO);
		close(tmp->fd[1]);
	}
}

void	free_tmp(t_traverser *tmp)
{
	if (tmp->fd)
		free(tmp->fd);
	free(tmp);
}
