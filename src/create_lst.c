/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:14:14 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/26 20:11:54 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*node_data(char **s, int *i)
{
	if (s[*i] && (s[*i][0] == '<' || s[*i][0] == '>'))
		return (create_redir(s, i));
	else if (s[*i] && s[*i][0] == '|')
		return (create_pipe(i));
	else
		return (create_cmd(s, i));
}

/*
	Creates a linked list of tokens
*/
t_list	*create_lst(char **s)
{
	t_list	*start;
	t_list	*tmp;
	void	*node;
	int		i;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	start = NULL;
	while (s[i])
	{
		node = node_data(s, &i);
		if (!node)
			return (start);
		tmp = ft_lstnew(node);
		ft_lstadd_back(&start, tmp);
	}
	return (start);
}
