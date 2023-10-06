/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:22:21 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/23 07:45:37 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*create_substr(char *s, int i)
{
	char	*str;
	int		j;

	j = 1;
	if (s[i + 1] == '?')
		return (ft_strdup("$?"));
	else if (s[i + 1] == '$')
		return (ft_strdup("$$"));
	while (s[i + j] && (ft_isalnum(s[i + j]) || s[i + j] == '_'))
		j++;
	str = ft_substr(s, i, j);
	return (str);
}

static int	get_length_for_fusion(char *token, char *s, int i)
{
	int	j;

	if (token[i + 1] == '?')
		j = 2;
	else if (token[i + 1] == '$')
	{
		free(s);
		s = ft_strdup("");
		j = 2;
	}
	else
	{
		j = 1;
		while (token[i + j]
			&& (ft_isalnum(token[i + j]) || token[i + j] == '_'))
		{
			j++;
		}
	}
	return (j);
}

static char	*fuse_token_with_str(char *token, char *s, int i)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		j;

	j = get_length_for_fusion(token, s, i);
	tmp = ft_substr(token, 0, i);
	str = ft_strjoin(tmp, s);
	free(tmp);
	tmp = ft_substr(token, i + j, ft_strlen(token));
	tmp2 = ft_strjoin(str, tmp);
	i = i + ft_strlen(s);
	free(s);
	free(str);
	free(tmp);
	free(token);
	return (tmp2);
}

/*
	deallocates s and returns allocated variable value
*/
char	*conv_to_env_var(char *s, t_list *env, int exit_status, int i)
{
	char	*str;
	char	*tmp;

	tmp = create_substr(s, i);
	if (!tmp)
		return (free(s), NULL);
	else if (ft_strncmp(tmp, "$?\0", 3) == 0)
	{
		free(tmp);
		str = ft_itoa(exit_status);
	}
	else if (ft_strncmp(tmp, "$$\0", 3) == 0)
	{
		free(tmp);
		str = ft_strdup("$$");
	}
	else
		str = env_var(env, tmp);
	if (!str)
		return (s);
	s = fuse_token_with_str(s, str, i);
	return (s);
}
