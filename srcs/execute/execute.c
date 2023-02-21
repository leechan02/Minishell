/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/21 19:11:50 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	only_process(t_tokens *tokens, char **env, int flag)
{
	pid_t	pid;
	int		fd;
	char	**name;

	name = find_here_doc(tokens, &flag);
	if (is_builtin(tokens[0]) && flag != 1)
	{
		fd = dup(STDOUT_FILENO);
		find_redir(&tokens[0], 0, 2, 1);
		exec_builtin(tokens, dup_env);
		g_exit = !exec_builtin(tokens, dup_env);
		dup2(fd, STDOUT_FILENO);
	}
	else if (flag != 1)
	{
		setting_signal(CHILD_EXECVE);
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
	int	flag;

	flag = 0;
	if (pipe_num == 0)
<<<<<<< HEAD
		only_process(tokens, dup_env);
	else
		pipex(pipe_num + 1, tokens, dup_env);
=======
		only_process(tokens, env, flag);
	else
		pipex(pipe_num + 1, tokens, env, flag);
>>>>>>> 5eaad37fb753e703704e86491872682b4925ba89
	return (SUCCESS);
}
