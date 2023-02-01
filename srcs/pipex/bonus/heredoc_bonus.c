/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:52:17 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/23 11:26:39 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char **av, int fd[2])
{
	char	*line;

	while (1)
	{
		write(STDIN_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == 0 || ft_strcmp(line, av[2]) == 1)
			return ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	here_pipex(char **av, char **env, pid_t pid[2], int fd[2][2])
{
	pipe(fd[0]);
	pipe(fd[1]);
	here_doc(av, fd[1]);
	close(fd[1][1]);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		close(fd[0][0]);
		dup2(fd[1][0], STDIN_FILENO);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][1]);
		exec(av[3], env);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		close(fd[0][1]);
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		exec(av[4], env);
	}
	close(fd[0][0]);
	close(fd[0][1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}
