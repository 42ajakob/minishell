/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:07:38 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/27 03:35:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_unknown(char *cmd, char *error)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

void	exit_mish(t_minishell *mish)
{
	int	exit_status;

	if (mish->envp)
		mish->envp = free_split(mish->envp);
	if (mish->tokens)
		mish->tokens = del_lst(mish->tokens);
	if (mish->env_lst)
		mish->env_lst = free_env(mish->env_lst);
	exit_status = mish->exit_status;
	free(mish);
	exit(exit_status);
}

int	prompt(t_minishell	*mish, char **envp)
{
	init_envp(mish, envp);
	mish->env_lst = copy_env(mish->envp);
	handle_signals();
	while (true)
	{
		mish->input = readline("$ ");
		if (mish->input == NULL)
			break ;
		else if (mish->input[0] == '\0')
		{
			free(mish->input);
			continue ;
		}
		add_history(mish->input);
		if (!init_lst(mish))
			continue ;
		executer(mish);
		mish->tokens = del_lst(mish->tokens);
	}
	return (exit_mish(mish), mish->exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mish;
	int			exit_status;

	mish = init_minishell();
	if (!mish)
		return (1);
	(void )argv;
	if (argc >= 2)
		return (1);
	exit_status = prompt(mish, envp);
	return (exit_status);
}
