/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 16:12:40 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_exit(char **token)
{
	int	i;
	int	j;

	i = 0;
	printf("exit\n");
	if (token[++i] == NULL)
		exit(0);
	else if (token[i] != NULL)
	{
		j = -1;
		while (ft_isdigit(token[i][++j]) != 0 && token[i][j] != '\0')
			;
		if (token[i][j] != '\0')
		{
			printf("minishell: exit: %s: numeric argument required\n", token[i]);
			exit (0);
		}
		if (token[++i] != NULL)
		{
			printf("minishell: exit: too many arguments\n");
			return (FALSE);
		}
	}
	exit(0);
}
