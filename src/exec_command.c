/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:13:25 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 01:39:53 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_cmd_from_default_path(t_traverser *tmp, char **envp)
{
	char	*bin_path;
	int		e_status;

	bin_path = get_bin(envp, tmp->cmd[0]);
	e_status = 0;
	if (!bin_path)
	{
		cmd_unknown(tmp->cmd[0], "command not found");
		if (tmp->fd)
			free(tmp->fd);
		free(tmp);
		return (EXIT_FAILURE);
	}
	else
	{
		tmp->cmd[0] = (char *)bin_path;
		execve(tmp->cmd[0], tmp->cmd, envp);
	}
	return (e_status);
}

int	execute_not_default_bin(t_traverser *tmp, char **envp)
{
	int		exit_status;

	exit_status = 1;
	if (access(tmp->cmd[0], X_OK) == 0 && is_directory(tmp->cmd[0]) == 1)
		execve(tmp->cmd[0], tmp->cmd, envp);
	else
	{
		cmd_unknown(tmp->cmd[0], "command not found");
		if (tmp->fd)
			free(tmp->fd);
		free(tmp);
		return (exit_status);
	}
	return (exit_status);
}

int	execute_cmd(t_minishell *mish, t_traverser *tmp)
{
	char	**tmp_env;

	if (mish->tokens == NULL
		|| (t_cmd *)tmp->cmd[0] == NULL
		|| !mish->envp)
		return (1);
	tmp_env = get_tmp_envp(mish->env_lst);
	if (is_builtin(tmp->cmd) == 1)
	{
		free_split(tmp_env);
		exec_builtin(mish, tmp);
	}
	else if (is_default_path(tmp->cmd[0], tmp_env) == 0)
	{
		mish->exit_status = execute_not_default_bin(tmp, tmp_env);
		free_split(tmp_env);
		return (mish->exit_status);
	}
	else
	{
		mish->exit_status = execute_cmd_from_default_path(tmp, tmp_env);
		free_split(tmp_env);
		return (mish->exit_status);
	}
	return (1);
}
