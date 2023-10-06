/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:43:14 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 03:45:00 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_single_cmd(t_minishell *mish)
{
	t_traverser	*tmp;
	int			pid;
	int			exit_status;

	tmp = traverse_files(mish->tokens);
	if (!tmp)
		return (1);
	exit_status = 0;
	if (is_builtin(tmp->cmd) == 2)
	{
		mish->exit_status = exec_builtin(mish, tmp);
		free_tmp(tmp);
		return (mish->exit_status);
	}
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		handle_redir(tmp);
		exit(execute_cmd(mish, tmp));
	}
	wait(&exit_status);
	free_tmp(tmp);
	return (exit_status);
}

int	exec_last_cmd(t_minishell *mish, t_traverser *tmp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		handle_redir(tmp);
		mish->exit_status = execute_cmd(mish, tmp);
		exit(mish->exit_status);
	}
	return (mish->exit_status);
}

int	exec_child_cmd(t_minishell *mish, t_traverser *tmp)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		handle_redir(tmp);
		mish->exit_status = execute_cmd(mish, tmp);
		exit(mish->exit_status);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return (mish->exit_status);
}

int	execute_multiple_cmd(t_minishell *mish, int total_pipes)
{
	t_traverser	*tmp;
	t_list		*tmp_list;
	int			fd_stdin;
	int			i;

	i = 0;
	tmp = traverse_files(mish->tokens);
	tmp_list = NULL;
	fd_stdin = dup(STDIN_FILENO);
	while (tmp && i < total_pipes)
	{
		exec_child_cmd(mish, tmp);
		tmp_list = tmp->pipe;
		free_tmp(tmp);
		tmp = traverse_files(tmp_list->next);
		i++;
	}
	exec_last_cmd(mish, tmp);
	free_tmp(tmp);
	while (waitpid(-1, 0, 0) != -1)
		;
	dup2(fd_stdin, STDIN_FILENO);
	close(fd_stdin);
	return (mish->exit_status);
}

int	executer(t_minishell *mish)
{
	int	total_pipes;

	if (!mish->env_lst)
		return (1);
	total_pipes = count_total_pipes(mish->tokens);
	if (total_pipes == 0)
	{
		return (execute_single_cmd(mish));
	}
	else
	{
		mish->exit_status = execute_multiple_cmd(mish, total_pipes);
		return (mish->exit_status);
	}
	return (0);
}
