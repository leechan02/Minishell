/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/12 15:40:02 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_echo(char **token, int fd)
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
		ft_putchar_fd('\n', fd);
		return ;
	}
	while (*(token + i) != NULL)
	{
		ft_putstr_fd(*(token + i), fd);
		ft_putchar_fd(' ', fd);
		i++;
	}
	if (nl != NO_NL)
		ft_putchar_fd('\n', fd);
}
