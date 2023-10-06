/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:12:24 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 07:49:10 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	empty_file(char *file)
{
	int	fd_write;

	fd_write = open(file, O_TRUNC);
	if (fd_write < 0)
		return ;
	close(fd_write);
}

void	read_write(char *open_word, int fd_write)
{
	char	*line;

	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			break ;
		if (ft_strncmp(line, open_word, ft_strlen(line)) == 0)
		{
			free(line);
			free(open_word);
			break ;
		}
		ft_putstr_fd(line, fd_write);
		write(fd_write, "\n", 1);
		free(line);
	}
}

char	*write_to_heredoc(char *open_word, int i)
{
	char	*tmp2;
	char	*tmp;
	int		fd_write;

	tmp2 = ft_itoa(i);
	tmp = ft_strjoin("/tmp/foo", tmp2);
	fd_write = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(tmp2);
	if (fd_write < 0)
		return (free(open_word), free(tmp), ft_strdup(""));
	read_write(open_word, fd_write);
	close(fd_write);
	return (tmp);
}

void	read_from_here_doc(char *file)
{
	int		fd_read;
	char	*line;

	fd_read = open(file, O_RDONLY);
	if (fd_read < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd_read);
		if (!line)
			return ;
		printf("%s", line);
		free(line);
	}
	close(fd_read);
}

int	here_doc(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "<<\0", 3) == 0 && cmd[i + 1])
		{
			cmd[i + 1] = write_to_heredoc(cmd[i + 1], i + 1);
			if (cmd[i + 1][0] == '\0')
				return (0);
			read_from_here_doc(cmd[i + 1]);
			i++;
		}
		i++;
	}
	return (1);
}
