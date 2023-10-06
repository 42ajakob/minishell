/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:46:27 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/26 01:31:15 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_closed(char *token, int j, char quote)
{
	j++;
	while (token[j])
	{
		if (token[j] == quote)
			return (j + 1);
		j++;
	}
	return (-1);
}

/*
	returns 
	1 on success
	0 on failure
*/
static int	check_quotes(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		while (tokens[i][j])
		{
			if (tokens[i][j] == '\'')
				j = is_closed(tokens[i], j, '\'');
			else if (tokens[i][j] == '"')
				j = is_closed(tokens[i], j, '"');
			else
				j++;
			if (j == -1)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	valid_pipe(char **split_input)
{
	int	i;

	i = 0;
	while (split_input[i])
	{
		if (split_input[i][0] == '|')
			if (split_input[i + 1] && split_input[i + 1][0] == '|')
				return (cmd_unknown(NULL, "||"), 0);
		i++;
	}
	if (split_input[0][0] == '|')
		return (cmd_unknown(NULL, "|"), 0);
	else if (split_input[i - 1][0] == '|')
		return (cmd_unknown(NULL, "|"), 0);
	return (1);
}

// edge case handeling? bash does it different because it has the commands
static int	valid_redir(char **split_input)
{
	int	i;

	i = 0;
	while (split_input[i])
	{
		if (split_input[i][0] == '<' || split_input[i][0] == '>')
		{
			if (strncmp(split_input[i], ">\0", 2) == 0
				|| strncmp(split_input[i], "<\0", 2) == 0)
				i++;
			else if (strncmp(split_input[i], ">>\0", 3) == 0
				|| strncmp(split_input[i], "<<\0", 3) == 0)
				i++;
			else
				return (cmd_unknown(NULL, split_input[i]), 0);
		}
		else
			i++;
	}
	return (1);
}

char	**check_error(char **split_input)
{
	if (!split_input)
		return (printf("Error: failed malloc\n"), NULL);
	if (valid_pipe(split_input) == 0)
		return (free_split(split_input), NULL);
	if (valid_redir(split_input) == 0)
		return (free_split(split_input), NULL);
	if (check_quotes(split_input) == 0)
	{
		printf("Error: unclosed quotes\n");
		return (free_split(split_input), NULL);
	}
	split_input = sort_split(split_input);
	if (!split_input)
		return (printf("Error: failed malloc\n"), NULL);
	return (split_input);
}
