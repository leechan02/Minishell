/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/16 10:23:57 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	here_doc(t_tokens *tokens, int i, char **file_name)
{
	char	*limiter;
	char	*line;
	int		fd;

	fd = open_file(tokens->token[i + 1], WRITE);
	limiter = ft_strjoin(tokens->token[i + 1], "\n");
	while (TRUE)
	{
		write (STDIN_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter);
}

void	find_here_doc(t_tokens *tokens, char **file_name)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i].token)
	{
		j = 0;
		while (tokens[i].token[j])
		{
			if (ft_strcmp(tokens[i].token[j], "<<") == 0)
			{
				replace_here_doc(&tokens[i], j);
				here_doc(&tokens[i], j, file_name);
			}
			j++;
		}
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
	find_here_doc(tokens, file_name);
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
		close(fd[0][0]);
		close(fd[1][1]);
		ft_memcpy(fd[0], fd[1], sizeof(int) * 2);
	}
	file_delete(file_name);
	return (wait_children(token_nb));
}
