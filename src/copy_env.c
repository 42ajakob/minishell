/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:47:01 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 04:13:25 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Receives text in format SOMETHING=SOMETHING_ELSE
and stores as
key: SOMETHING
value: SOMETHING_ELSE
*/
t_env	*parse_env_variable(char *s)
{
	t_env	*env;
	char	**split;

	split = ft_split(s, '=');
	env = (t_env *)malloc(sizeof(t_env));
	if (!split)
		return (NULL);
	if (!env)
		return (NULL);
	if (ft_isalpha(split[0][0]) != 1 && split[0][0] != '_')
	{
		cmd_unknown("export", "not a valid identifier");
		free(env);
		free_split(split);
		return (NULL);
	}
	if (get_split_len(split) > 2 || get_split_len(split) < 1)
		return (free(env), free_split(split), NULL);
	env->value = ft_strdup(split[1]);
	env->key = ft_strdup(split[0]);
	free_split(split);
	return (env);
}

/*
Reads env and creates a linked list with a copy of the original array
*/
t_list	*copy_env(char **env)
{
	t_list	*root;
	t_list	*tmp;
	t_env	*tmp_env;
	int		i;

	i = -1;
	if (!env || !env[++i])
		return (NULL);
	root = NULL;
	while (env[i])
	{
		tmp_env = parse_env_variable(env[i++]);
		if (!tmp_env)
			continue ;
		tmp = ft_lstnew((void *)tmp_env);
		if (!tmp)
		{
			free(tmp_env->key);
			free(tmp_env->value);
			free(tmp_env);
			continue ;
		}
		ft_lstadd_back(&root, tmp);
	}
	return (root);
}

/*
free list, list->content, content->next
free env, env->key, env->value
*/
t_list	*free_env(t_list *env)
{
	t_list	*next;

	while (env)
	{
		next = env->next;
		if (((t_env *)env->content)->key)
			free(((t_env *)env->content)->key);
		if (((t_env *)env->content)->value)
			free(((t_env *)env->content)->value);
		if (env->content)
			free(env->content);
		if (env)
			free(env);
		env = next;
	}
	return (NULL);
}
