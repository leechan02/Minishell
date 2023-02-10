/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/07 14:30:50 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_echo(char **token)
{
	int	i;
	int	nl;

	i = 0;
	nl = NL;
	if (ft_strcmp(*(token + i), "-n") == 0)
	{
		nl = NO_NL;
		i++;
	}
	if (*(token + i) == NULL)
	{
		if (nl == NO_NL)
			return ;
		write(1, "\n", 1);
		return ;
	}
	while (*(token + i) != NULL)
	{
		write (1, *(token + i), ft_strlen(*(token + i)));
		write (1, " ", 1);
		i++;
	}
	if (nl != NO_NL)
		write(1, "\n", 1);
}
