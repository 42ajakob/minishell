/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:43:11 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 03:49:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_fds(int *fd, int failed_input)
{
	if (failed_input)
		fd[0] = -1;
	else
		fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
}
