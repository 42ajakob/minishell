/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:00:11 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 01:43:55 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_paths(char **envp)
{
	int		i;
	char	*content;
	char	**tmp;
	char	**paths;

	content = NULL;
	paths = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			content = envp[i];
			break ;
		}
	}
	if (content)
	{
		tmp = ft_split(content, '=');
		content = ft_strdup(tmp[1]);
		paths = ft_split(content, ':');
		free_split(tmp);
		free(content);
	}
	return (paths);
}

char	*join_paths(char *path1, char *path2)
{
	char	*out;
	int		total_len;
	int		i;
	int		j;

	if (!path1 || !path2)
		return (NULL);
	total_len = ft_strlen(path1) + ft_strlen(path2) + 2;
	i = -1;
	j = -1;
	out = (char *)malloc(sizeof(char) * total_len);
	if (!out)
		return (NULL);
	while (path1[++i])
		out[i] = path1[i];
	out[i] = '/';
	i++;
	while (path2[++j])
	{
		out[i] = path2[j];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*get_bin(char **envp, char *cmd)
{
	char	**paths;
	char	*tmp_path;
	int		i;

	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		tmp_path = join_paths(paths[i], cmd);
		if (access(tmp_path, X_OK) == 0)
		{
			free_split(paths);
			return (tmp_path);
		}
		free(tmp_path);
	}
	free_split(paths);
	return (NULL);
}

/*
Returns 0 if it's a file and 1 otherwise.
*/
int	is_directory(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

int	is_default_path(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp_path;
	int		i;

	paths = get_paths(envp);
	if (!paths)
		return (0);
	i = -1;
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "/", 1) == 0)
		return (free_split(paths), 0);
	while (paths[++i])
	{
		tmp_path = join_paths(paths[i], cmd);
		if (access(tmp_path, X_OK) == 0)
		{
			free_split(paths);
			free(tmp_path);
			return (1);
		}
		free(tmp_path);
	}
	free_split(paths);
	return (0);
}
