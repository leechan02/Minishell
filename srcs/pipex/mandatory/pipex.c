/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:51 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/23 11:31:33 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	pipex(char *cmd1, char *cmd2, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec(cmd1, env);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		exec(cmd2, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	char	*arg_err;
	int		file_in;
	int		file_out;

	arg_err = "It must be like this : ./pipex file1 cmd1 cmd2 file2\n";
	if (ac == 5)
	{
		error(file_in = openfile(av[1], STDIN_FILENO));
		error(file_out = openfile(av[4], STDOUT_FILENO));
		dup2(file_in, STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO);
		pipex(av[2], av[3], env);
	}
	else
		write(2, arg_err, ft_strlen(arg_err));
	return (0);
}
