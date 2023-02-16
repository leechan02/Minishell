/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/16 17:26:08 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	file_delete(char **file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		unlink(file_name[i]);
		i++;
	}
}

void	pipex(int token_nb, t_tokens *tokens, char **env)
{
	int		fd[2][2];
	int		cmd;
	pid_t	pid;
	char	**file_name;

	cmd = -1;
	fd[0][0] = STDIN_FILENO;
	file_name = find_here_doc(tokens);
	while (++cmd < token_nb)
	{
		pipe(fd[1]);
		pid = fork();
		if (pid == 0)
		{
			close(fd[1][0]);
			dup2(fd[0][0], STDIN_FILENO);
			find_redir(&tokens[cmd], fd[1][1], token_nb, cmd);
			exec(tokens[cmd].token, env);
		}
		if (fd[0][0] != 0)
			close(fd[0][0]);
		close(fd[1][1]);
		ft_memcpy(fd[0], fd[1], sizeof(int) * 2);
	}
	wait_children(token_nb);
	file_delete(file_name);
}
