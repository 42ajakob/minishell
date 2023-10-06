/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:25:46 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 03:48:22 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_split_len(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}

static int	status(char **input, int split_len)
{
	int		status;

	status = ft_atoi(input[1]);
	if (status == -1)
		return (255);
	if (split_len > 2)
	{
		cmd_unknown("exit", ": too many arguments");
		return (-1);
	}
	return (status % 256);
}

/*
exit 4 3 2:
	bash: exit: too many arguments
	keep the shell
	exit status 1
exit abc:
	exit with 255
exit 5:
	exit with 5
*/
int	exit_builtin(char **input, int exit_status)
{
	int		split_len;

	split_len = get_split_len(input);
	if (split_len == 1)
	{
		if (exit_status == -1)
			return (1);
		return (exit_status);
	}
	if (ft_str_isdigit(input[1]) == 1)
		return (status(input, split_len));
	cmd_unknown("exit", ": abc: numeric argument required");
	return (255);
}
