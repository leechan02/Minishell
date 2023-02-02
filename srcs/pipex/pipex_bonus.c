/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/23 12:53:08 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(int return_value)
{
	if (return_value < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

int	openfile(char *filename, int fd)
{
	if (fd == 1)
		return (open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (fd == HEREDOC)
		return (open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644));
	else
		return (open(filename, O_RDONLY));
}

void	exec(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**paths;
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	path = ft_strfind(env, "PATH=");
	path = ft_strtrim(path, "PATH=");
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmds[0]);
		if (access(path, X_OK) == 0)
			break ;
		i++;
	}
	execve(path, cmds, env);
	exit(EXIT_FAILURE);
}

void	pipex(char **av, int ac, char **env)
{
	pid_t	pid;
	int		new_fd[2];
	int		old_fd[2];
	int		cmd;

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
			exec(av[cmd], env);
		}
		close(old_fd[0]);
		close(new_fd[1]);
		ft_memcpy(old_fd, new_fd, sizeof(int) * 2);
		cmd++;
	}
	dup2(old_fd[0], STDIN_FILENO);
	exec(av[ac - 2], env);
}

int	main(int ac, char **av, char **env)
{
	int		file_in;
	int		file_out;
	int		fd[2][2];
	pid_t	pid[2];

	if (ac >= 5)
	{
		if (ft_strcmp("here_doc", av[1]) == 1)
		{
			error(dup2(openfile(av[5], HEREDOC), STDOUT_FILENO));
			here_pipex(av, env, pid, fd);
		}
		else
		{
			error(file_in = openfile(av[1], STDIN_FILENO));
			error(file_out = openfile(av[ac - 1], STDOUT_FILENO));
			dup2(file_in, STDIN_FILENO);
			dup2(file_out, STDOUT_FILENO);
			pipex(av, ac, env);
		}
	}
	else
		write(2, ERROR, ft_strlen(ERROR));
	return (0);
}
