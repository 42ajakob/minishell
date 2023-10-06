/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_total_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:29:59 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/21 00:35:39 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Returns the number of pipes in the list
*/
int	count_total_pipes(t_list *start)
{
	t_list	*tmp;
	int		i;

	if (!start)
		return (0);
	tmp = start;
	i = 0;
	while (tmp->next)
	{
		if (((t_cmd *)tmp->content)->type == 2)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
