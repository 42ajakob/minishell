/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:42:02 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/27 03:09:40 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	*init_minishell(void)
{
	t_minishell	*mish;

	mish = (t_minishell *)malloc(sizeof(t_minishell));
	if (!mish)
		return (NULL);
	mish->cmd = NULL;
	mish->envp = NULL;
	mish->env_lst = NULL;
	mish->input = NULL;
	mish->tokens = NULL;
	mish->exit_status = 0;
	return (mish);
}

char	**add_path_to_env(void)
{
	char	**envp;
	char	*str;

	str = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin");
	envp = (char **)malloc(sizeof(char *) * 2);
	if (!envp)
		return (NULL);
	envp[0] = ft_strdup(str);
	envp[1] = NULL;
	return (envp);
}

void	init_envp(t_minishell *mish, char **envp)
{
	int	i;

	i = 0;
	if (!envp || !envp[0])
		mish->envp = add_path_to_env();
	else
	{
		while (envp[i])
			i++;
		mish->envp = ft_calloc(sizeof(char *), i + 1);
		i = 0;
		while (envp[i])
		{
			mish->envp[i] = ft_strdup(envp[i]);
			i++;
		}
	}
}

int	init_lst(t_minishell *mish)
{
	mish->cmd = mini_split(mish->input);
	free(mish->input);
	if (!mish->cmd)
		return (0);
	if (!here_doc(mish->cmd))
	{
		mish->cmd = free_split(mish->cmd);
		return (0);
	}
	mish->cmd = check_error(mish->cmd);
	if (!mish->cmd)
		return (0);
	mish->tokens = create_lst(mish->cmd);
	if (!mish->tokens)
		return (0);
	mish->cmd = free_split(mish->cmd);
	expander(mish->tokens, mish->env_lst, mish->exit_status);
	if (!mish->tokens)
		return (0);
	return (1);
}
