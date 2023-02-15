/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:52:17 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/15 15:57:28 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	wait_children(int num_of_children)
{
	int	i;

	i = 0;
	while (i < num_of_children)
	{
		ft_assert(waitpid(-1, NULL, 0) != -1, "waitpid error" );
		i++;
	}
}

char	**find_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	ft_assert((path != NULL), "Failed to execute ft_split ");
	return (path);
}

void	exec(char **token, char **envp)
{
	char	**path;
	char	*cmd;
	int		i;

	path = find_path(envp);
	i = 0;
	while (path[i] != NULL)
	{
		cmd = ft_strjoin(path[i], "/");
		cmd = ft_strjoin(cmd, token[0]);
		if (access(cmd, X_OK) == 0)
			break ;
		i++;
	}
	if (access(cmd, X_OK) == -1)
		ft_assert(FALSE, "Failed to execute access ");
	ft_assert(!(execve(cmd, token, envp) == -1), "Failed to execute execve ");
}

int	open_file(char *file, int flag)
{
	int	fd;

	if (flag == READ)
		fd = open(file, O_RDONLY);
	else if (flag == WRITE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == HERE_DOC)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_assert(!(fd < 0), "Failed to open files " );
	return (fd);
}
