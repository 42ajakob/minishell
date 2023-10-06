/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:32:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/25 04:16:22 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*get_prev_item(t_list *list, t_list *to_search)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->next == to_search)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	remove_env_variable(t_list **env, t_list *variable)
{
	t_list	*prev;
	t_env	*tmp_env;

	tmp_env = variable->content;
	prev = get_prev_item(*env, variable);
	if (prev)
		prev->next = variable->next;
	else
		*env = variable->next;
	free(tmp_env->key);
	free(tmp_env->value);
	free(variable->content);
	free(variable);
}

int	unset(t_list **env, char **input)
{
	t_list	*variable;
	int		i;

	if (get_split_len(input) <= 1)
		return (0);
	i = 1;
	while (input[i])
	{
		variable = search_variable(*env, input[i]);
		if (variable)
			remove_env_variable(env, variable);
		i++;
	}
	return (0);
}
