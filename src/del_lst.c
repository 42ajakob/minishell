/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:43:11 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/26 03:21:21 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_lst_node_content(void *content)
{
	t_cmd	*cmd;
	t_redir	*redir;

	cmd = (t_cmd *)content;
	if (cmd->type == 1)
	{
		free_split(cmd->cmd);
	}
	else if (cmd->type == 3)
	{
		redir = (t_redir *)content;
		free(redir->file);
	}
}

/*
Frees the memory allocated for the tokenized linked list
*/
t_list	*del_lst(t_list *root)
{
	ft_lstiter(root, &delete_lst_node_content);
	ft_lstclear(&root);
	return (NULL);
}
