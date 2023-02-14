/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:03:56 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 18:50:37 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	check_redir(t_tokens *tokens, int i)
{
	> < >> => open file << => here_doc
	dup2
	
}

void	find_redir(t_tokens *tokens)
{
	int	i;

	i = 0;
	while (tokens->token[i] != NULL)
	{
		if (tokens->redir[i] == TRUE)
			/* check_redir(tokens, i + 1); */
		i++;
	}
}