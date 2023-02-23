/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/23 14:15:12 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	process_signal(t_tokens *tokens)
{
	int	i;
	int	find;

	i = 0;
	find = 0;
	while (tokens->token[i])
	{
		if (ft_strcmp(tokens->token[i], "cat") == 0)
		{
			setting_signal(CHILD_EXECVE);
			find = 1;
		}
		i++;
	}
	if (find == 0)
		signal(SIGINT, SIG_IGN);
}

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
		g_exit = exec_builtin(tokens, env);
		dup2(fd, STDOUT_FILENO);
	}
	else if (flag != 1)
	{
		process_signal(tokens);
		pid = fork();
		if (pid == 0)
		{
			find_redir(&tokens[0], 0, 2, 1);
			exec(tokens->token, env);
		}
		wait_children(1);
	}
	file_delete(name);
	return (g_exit);
}

int	execute(t_tokens *tokens, char **env, int pipe_num)
{
	int	flag;

	flag = 0;
	if (pipe_num == 0)
		only_process(tokens, env, flag);
	else
		pipex(pipe_num + 1, tokens, env, flag);
	return (g_exit);
}
