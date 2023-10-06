/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tmp_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 00:02:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 00:05:16 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_lst_len(t_list *env_lst)
{
	t_list	*tmp;
	int		i;

	if (!env_lst)
		return (0);
	tmp = env_lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	*get_env_var(char *key, char *value)
{
	char	*tmp_key;
	char	*out;

	tmp_key = ft_strjoin(key, "=");
	out = ft_strjoin(tmp_key, value);
	free(tmp_key);
	return (out);
}

char	**get_tmp_envp(t_list *env_lst)
{
	char	**envp;
	t_list	*tmp;
	t_env	*env_var;
	int		len;
	int		i;

	len = get_lst_len(env_lst);
	envp = (char **)malloc(sizeof(char *) * (len + 1));
	envp[len] = NULL;
	tmp = env_lst;
	i = 0;
	while (i < len)
	{
		env_var = tmp->content;
		envp[i] = get_env_var(env_var->key, env_var->value);
		tmp = tmp->next;
		i++;
	}
	return (envp);
}
