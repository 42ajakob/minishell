/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:15:44 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/25 03:52:22 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Returns the pointer to the environmental variable or NULL
if doesn't exists.
*/
t_list	*search_variable(t_list *env, char *key)
{
	t_list	*tmp;
	t_env	*tmp_env;

	tmp = env;
	while (tmp)
	{
		tmp_env = tmp->content;
		if (ft_strncmp(key, tmp_env->key, ft_strlen(key) + 1) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	print_env(t_list *env)
{
	t_list	*tmp;
	t_env	*env_variable;

	tmp = env;
	while (tmp)
	{
		env_variable = tmp->content;
		printf("%s=%s\n", env_variable->key, env_variable->value);
		tmp = tmp->next;
	}
	return (0);
}
