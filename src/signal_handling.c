/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:05:29 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 00:34:35 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_printing_signals(void)
{
	struct termios	termios_new;

	tcgetattr(0, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_new);
}

/*
Handle ctrl+\
*/
void	handle_sigquit(int signal)
{
	(void)signal;
	rl_on_new_line();
	rl_redisplay();
}

/*
Handle ctrl+c
*/
void	handle_sigint(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signals(void)
{
	struct sigaction	sa_sigquit;
	struct sigaction	sa_sigint;

	remove_printing_signals();
	sa_sigquit.sa_flags = 0;
	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigquit.sa_handler = handle_sigquit;
	sa_sigint.sa_handler = handle_sigint;
	sigaction(SIGQUIT, &sa_sigquit, NULL);
	sigaction(SIGINT, &sa_sigint, NULL);
}
