/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:33:15 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 00:46:45 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export_without_arguments(t_list *env)
{
	t_list	*tmp;
	t_env	*tmp_variable;

	tmp = env;
	while (tmp)
	{
		tmp_variable = tmp->content;
		printf("declare -x %s=%s\n", tmp_variable->key, tmp_variable->value);
		tmp = tmp->next;
	}
}

/*
Searches in envp for the variable. If exists modify it's value
with the specified one. Otherwise it creates it.
*/
void	modify_env_variable(t_list *env, t_env *env_var)
{
	t_list	*tmp;
	t_env	*tmp_env;

	tmp = search_variable(env, env_var->key);
	if (tmp)
	{
		tmp_env = tmp->content;
		free(tmp_env->value);
		free(tmp_env->key);
		free(tmp_env);
		tmp->content = (void *)env_var;
	}
	else
	{
		tmp = ft_lstnew((void *)env_var);
		ft_lstadd_back(&env, tmp);
	}
}

int	export(char **input, t_list *env)
{
	t_env	*env_variable;
	int		i;

	i = 1;
	if (get_split_len(input) <= 1)
		print_export_without_arguments(env);
	while (input[i])
	{
		env_variable = parse_env_variable(input[i]);
		if (env_variable == NULL)
		{
			i++;
			continue ;
		}
		modify_env_variable(env, env_variable);
		i++;
	}
	return (0);
}
