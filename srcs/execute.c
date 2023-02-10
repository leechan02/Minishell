/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/10 19:23:38 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	check_redirection(char **token)
{
	int	fd;
	fd = open_file(*file, flag)
	/* dup2 호출 */
}

int	execute(t_tokens *tokens, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		i;
	
	/* default로 STDOUT을 pipe로 연결 */
	/* 1. token[i]부터 ->redirecion 처리, T/F도 판별 */
	/* 2. cmd 판별(builtin or not), To handle error case */
	/* 3. pipe ? */
	/* 4. pipe 병렬 처리 */
	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO:
	i = 1;
	while (i < tokens)
		pid = fork();
	/* 마지막 token - 1 까지만 반복문에 들어간다. */
	while (tokens->token[i + 1] != NULL)
	{
		/* | 뒤에 아무것도 오지 않는 경우 */
		if (token->token[i] == NULL)
			return (FAIL);
		fd = pipex(tokens->token[i], env, fd);
		check_redirection(tokens->token[i]);
		
		i++;
	}
	return (SUCCESS);
}
