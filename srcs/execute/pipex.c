/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:43:46 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/15 14:37:49 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// void	here_doc(char **tokens, char **env, int outfile_fd)
// {
// 	char	*limiter;
// 	char	*line;
// 	int		fd[2];

// 	limiter = ft_strjoin(tokens[2], "\n");
// 	pipe(fd);
// 	while (TRUE)
// 	{
// 		write (STDIN_FILENO, "> ", 2);
// 		line = get_next_line(STDIN_FILENO);
// 		if (line == NULL || ft_strcmp(line, limiter) == 0)
// 			break ;
// 		write(fd, line, ft_strlen(line));
// 		free(line);
// 	}
// 	free(line);
// 	free(limiter);
// 	close(fd[1]);
// 	pipex(fd[0], tokens, env);
// }

void	pipex(int token_nb, t_tokens *tokens, char **env)
{
	int		old_fd[2];
	int		new_fd[2];
	int		cmd;
	pid_t	pid;

	cmd = -1;
	old_fd[0] = STDIN_FILENO;
	while (++cmd < token_nb)
	{
		pipe(new_fd);
		pid = fork();
		if (pid == 0)
		{
			close(new_fd[0]);
			/* heredoc? */
			dup2(old_fd[0], STDIN_FILENO);
			if (cmd != token_nb - 1)
				dup2(new_fd[1], STDOUT_FILENO);
			find_redir(&tokens[cmd]);
			exec(tokens[cmd].token, env);
		}
		close(old_fd[0]);
		close(new_fd[1]);
		ft_memcpy(old_fd, new_fd, sizeof(int) * 2);
	}
	return (wait_children(token_nb));
}
