/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:39 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/05 18:09:15 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*j_free(char *str)
{
	free(str);
	return (NULL);
}

char	*get_cache(char *cache)
{
	char	*new;
	int		length;
	int		i;

	if (indexof(cache, '\n') < 0)
		return (j_free(cache));
	i = indexof(cache, '\n') + 1;
	length = 0;
	while (cache[i + length])
		length++;
	new = j_substr(cache, i, length);
	j_free(cache);
	return (new);
}

char	*get_txt(int fd, char *cache)
{
	char	*buff;
	int		read_status;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (j_free(cache));
	read_status = BUFFER_SIZE;
	while (indexof(cache, '\n') == -1 && read_status == BUFFER_SIZE)
	{
		read_status = read(fd, buff, BUFFER_SIZE);
		if (read_status <= 0)
		{
			j_free(buff);
			if (read_status == 0)
				return (cache);
			return (j_free(cache));
		}
		buff[read_status] = '\0';
		cache = j_strjoin(cache, buff);
	}
	j_free (buff);
	return (cache);
}

char	*get_one_line(char *cache)
{
	size_t	length;

	length = 0;
	if (cache == NULL || !cache[0])
		return (NULL);
	while (cache[length] != '\n' && cache[length] != '\0')
		length++;
	if (cache[length] == '\n')
		length++;
	return (j_substr(cache, 0, length));
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (cache == NULL)
	{
		cache = malloc(sizeof(char));
		if (!cache)
			return (NULL);
		cache[0] = '\0';
	}
	cache = get_txt(fd, cache);
	line = get_one_line(cache);
	cache = get_cache(cache);
	return (line);
}
