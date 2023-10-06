/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:25:24 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 21:33:53 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char **cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd[0], "env\0", 4) == 0
		|| ft_strncmp(cmd[0], "echo\0", 5) == 0
		|| ft_strncmp(cmd[0], "pwd\0", 4) == 0)
	{
		return (1);
	}
	else if (ft_strncmp(cmd[0], "exit\0", 5) == 0
		|| ft_strncmp(cmd[0], "export\0", 7) == 0
		|| ft_strncmp(cmd[0], "unset\0", 6) == 0
		|| ft_strncmp(cmd[0], "cd\0", 3) == 0)
	{
		return (2);
	}
	return (0);
}

int	exec_builtin(t_minishell *mish, t_traverser *tmp)
{
	char	**cmd;

	cmd = tmp->cmd;
	if (ft_strncmp(cmd[0], "exit\0", 5) == 0)
	{
		mish->exit_status = exit_builtin(cmd, mish->exit_status);
		exit_mish(mish);
	}
	else if (ft_strncmp(cmd[0], "cd\0", 3) == 0)
		return (cd(mish->env_lst, cmd));
	else if (ft_strncmp(cmd[0], "env\0", 4) == 0)
		return (print_env(mish->env_lst));
	else if (ft_strncmp(cmd[0], "export\0", 7) == 0)
		return (export(cmd, mish->env_lst));
	else if (ft_strncmp(cmd[0], "echo\0", 5) == 0)
		return (echo(cmd));
	else if (ft_strncmp(cmd[0], "pwd\0", 4) == 0)
		return (pwd());
	else if (ft_strncmp(cmd[0], "unset\0", 6) == 0)
		return (unset(&mish->env_lst, cmd));
	return (1);
}
