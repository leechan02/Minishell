/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/16 16:27:33 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	only_process(t_tokens *tokens, char **env)
{
	pid_t	pid;
	int		fd;
	char	**name;

	name = find_here_doc(tokens);
	if (is_builtin(tokens[0]))
	{
		fd = dup(STDOUT_FILENO);
		find_redir(&tokens[0], 0, 2, 1);
		exec_builtin(tokens, env);
		dup2(fd, STDOUT_FILENO);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			find_redir(&tokens[0], 0, 2, 1);
			exec(tokens->token, env);
		}
		wait_children(1);
	}
	file_delete(name);
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
