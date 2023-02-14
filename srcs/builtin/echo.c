/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 13:32:10 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_redir(t_tokens *tokens, int i)
{
	int	fd;
	int	j;

	fd = 1;
	j = 0;
	while (tokens->token[i][j] != NULL)
	{
		if (ft_strcmp(tokens->token[i][j], "<") == 0 && tokens->redir[j] == TRUE)
	}
}

static int	is_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	*nl = NO_NL;
	return (TRUE);
}

int	ft_echo(t_tokens *tokens, int i)
{
	int	nl;
	int	fd;
	int	j;

	j = 0;
	nl = NL;
	fd = is_redir(tokens);
	if (ft_strcmp(*(token + j), "-n") == 0)
	{
		nl = NO_NL;
		j++;
	}
	if (*(token + j) == NULL)
	{
		if (nl == NL)
			return (ft_putchar_fd('\n', fd), TRUE);
	}
	while (*(token + j) != NULL)
	{
		ft_putstr_fd(*(token + j), fd);
		/* if (마지막일 때, 공백 출력 x) */
		ft_putchar_fd(' ', fd);
		j++;
	}
	if (nl != NO_NL)
		return (ft_putchar_fd('\n', fd), TRUE);
}
