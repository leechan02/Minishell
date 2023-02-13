/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/13 19:41:08 by nakoo            ###   ########.fr       */
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

static int	is_n(char *token)
{
	int	i;

	i = 0;
	while (token[i] != NULL)
	{
		if (token[i] != 'n')
			return (NL);
		i++;
	}
	return (NO_NL);
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
		ft_putchar_fd(' ', fd);
		j++;
	}
	if (nl != NO_NL)
		return (ft_putchar_fd('\n', fd), TRUE);
}
