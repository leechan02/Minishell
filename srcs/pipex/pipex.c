/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/14 15:31:49 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char **av, char **envp, int outfile_fd)
{
	char	*limiter;
	char	*line;
	int		fd[2];

	limiter = ft_strjoin(av[2], "\n");
	pipe(fd);
	while (TRUE)
	{
		write (STDIN_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter);
	close(fd[1]);
	pipex(fd, av, envp);
}

void	pipex(int ac, char **av, char **envp)
{
	int		old_fd[2];
	int		new_fd[2];
	int		cmd;
	pid_t	pid;

	cmd = 2;
	old_fd[0] = STDIN_FILENO;
	while (cmd < ac - 2)
	{
		pipe(new_fd);
		pid = fork();
		if (pid == 0)
		{
			close(new_fd[0]);
			dup2(old_fd[0], STDIN_FILENO);
			dup2(new_fd[1], STDOUT_FILENO);
			exec(av[cmd], envp);
		}
		close(old_fd[0]);
		close(new_fd[1]);
		ft_memcpy(old_fd, new_fd, sizeof(int) * 2);
		cmd++;
	}
	dup2(old_fd[0], STDIN_FILENO);
	exec(av[ac - 2], envp);
}
