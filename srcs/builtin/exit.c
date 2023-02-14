/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/13 20:49:24 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_exit(char **token)
{
	int	i;

	i = -1;
	while (ft_strcmp(token[++i], "exit") != 0)
		;
	if (ft_isdigit(ft_atoi(token[i + 1]) == 1) \
	&& ft_isdigit(ft_atoi(token[i + 2]) == 1))
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n")
		return (FALSE);
	}
	if (/* exit 바로 뒤의 인자가 숫자가 아닐 경우 */)
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n", token[i + 1]);
		exit(0);
	}
	exit(0);
}
