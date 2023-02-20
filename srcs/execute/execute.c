/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/20 19:58:03 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	only_process(t_tokens *tokens, char **dup_env)
{
	pid_t	pid;
	int		fd;
	char	**name;

	name = find_here_doc(tokens);
	if (is_builtin(tokens[0]) && !name)
	{
		fd = dup(STDOUT_FILENO);
		find_redir(&tokens[0], 0, 2, 1);
		exec_builtin(tokens, dup_env);
		g_exit = !exec_builtin(tokens, dup_env);
		dup2(fd, STDOUT_FILENO);
	}
	else if (!name)
	{
		pid = fork();
		if (pid == 0)
		{
			find_redir(&tokens[0], 0, 2, 1);
			exec(tokens->token, dup_env);
		}
		wait_children(1);
	}
	file_delete(name);
	return (SUCCESS);
}

int	execute(t_tokens *tokens, char **dup_env, int pipe_num)
{
	if (pipe_num == 0)
		only_process(tokens, dup_env);
	else
		pipex(pipe_num + 1, tokens, dup_env);
	return (SUCCESS);
}
