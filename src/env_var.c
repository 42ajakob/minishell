/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:09:08 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 05:51:01 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
If the environmental variable is found in the env linked list returns
the string inside that variable. Otherwise returns NULL.
*/
char	*find_var_value(t_list *env, char *string)
{
	t_list	*var_node;
	char	*s;

	var_node = search_variable(env, string);
	if (!var_node)
		return (NULL);
	s = ((t_env *)var_node->content)->value;
	return (s);
}

/*
Saves the value of the environmental variable in a string.
*/
char	*save_var(char *s, t_list *env)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(&s[1]);
	if (!tmp)
		return (NULL);
	tmp2 = find_var_value(env, tmp);
	free(tmp);
	if (!tmp2)
		return (NULL);
	str = ft_strdup(tmp2);
	return (str);
}

/*
	returns env variable or \0 if not found
*/
char	*env_var(t_list *env, char *s)
{
	char	*str;

	if (!s)
		return (NULL);
	str = save_var(s, env);
	free(s);
	if (!str)
		return (ft_strdup(""));
	return (str);
}
