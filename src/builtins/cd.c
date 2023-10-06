/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:47:29 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 06:52:15 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	replace_old_new_var_move(char *curr_dir, t_list *env)
{
	t_env	*old_pwd_var;
	t_env	*new_pwd_var;

	new_pwd_var = (t_env *)malloc(sizeof(t_env));
	if (!new_pwd_var)
		return (2);
	old_pwd_var = (t_env *)malloc(sizeof(t_env));
	if (!old_pwd_var)
		return (2);
	old_pwd_var->key = ft_strdup("OLDPWD");
	old_pwd_var->value = curr_dir;
	modify_env_variable(env, old_pwd_var);
	curr_dir = getcwd(NULL, 255);
	if (!curr_dir)
		return (2);
	new_pwd_var->key = ft_strdup("PWD");
	new_pwd_var->value = curr_dir;
	modify_env_variable(env, new_pwd_var);
	return (0);
}

t_env	*replace_old_new_var_go_home(char *curr_dir, t_list *env)
{
	t_env	*old_pwd_var;
	t_env	*new_pwd_var;

	new_pwd_var = (t_env *)malloc(sizeof(t_env));
	if (!new_pwd_var)
		return (NULL);
	old_pwd_var = (t_env *)malloc(sizeof(t_env));
	if (!old_pwd_var)
		return (NULL);
	old_pwd_var->key = ft_strdup("OLDPWD");
	old_pwd_var->value = curr_dir;
	modify_env_variable(env, old_pwd_var);
	new_pwd_var->key = ft_strdup("PWD");
	new_pwd_var->value = env_var(env, ft_strdup("$HOME"));
	return (new_pwd_var);
}

/*
Changes directory. If it changed directory returns 0 otherwise 1.
*/
int	cd(t_list *env, char **input)
{
	char	*curr_dir;
	t_env	*new_pwd_var;

	curr_dir = getcwd(NULL, 255);
	if (!curr_dir)
		return (2);
	if (input[1] && chdir(input[1]) == 0)
		return (replace_old_new_var_move(curr_dir, env));
	else if (input[0])
	{
		new_pwd_var = replace_old_new_var_go_home(curr_dir, env);
		if (new_pwd_var->value[0] == '\0')
		{
			free(new_pwd_var->value);
			free(new_pwd_var->key);
			free(new_pwd_var);
			return (cmd_unknown("cd", "HOME not set"), 2);
		}
		chdir(new_pwd_var->value);
		modify_env_variable(env, new_pwd_var);
		return (0);
	}
	free(curr_dir);
	return (1);
}
