/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:20:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/25 04:22:46 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(char **input)
{
	int	i;

	if (input[1] && ft_strncmp(input[1], "-n", 2) == 0)
	{
		i = 2;
		while (input[i])
			printf("%s", input[i++]);
	}
	else
	{
		i = 1;
		while (input[i])
		{
			if (input[i + 1])
				printf("%s ", input[i]);
			else
				printf("%s", input[i]);
			i++;
		}
		printf("\n");
	}
	return (0);
}
