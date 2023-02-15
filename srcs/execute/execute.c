/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/15 15:55:21 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	only_process(t_tokens *tokens, char **env)
{
	pid_t	pid;
	int		fd;

	if (is_builtin(tokens[0]))
	{
		fd = dup(STDOUT_FILENO);
		find_redir(&tokens[0]);
		exec_builtin(tokens, env);
		dup2(fd, STDOUT_FILENO);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			find_redir(&tokens[0]);
			exec(tokens->token, env);
		}
		wait_children(1);
	}
	return (SUCCESS);
}

int	execute(t_tokens *tokens, char **env, int pipe_num)
{
	if (pipe_num == 0)
		only_process(tokens, env);
	else
		pipex(pipe_num + 1, tokens, env);
	return (SUCCESS);
}
