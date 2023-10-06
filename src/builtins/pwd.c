/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:32 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/25 04:01:28 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(NULL, 255);
	printf("%s\n", pwd);
	if (pwd)
		free(pwd);
	return (0);
}
