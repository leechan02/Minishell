/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:52:44 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 18:53:03 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define FAIL 0
# define SUCCESS 1

# include "../libft/includes/libft.h"
# include "minishell.h"
# include "builtin.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

enum e_flag {
	READ,
	WRITE,
	HERE_DOC
};

/* redirect */
void	find_redir(t_tokens *tokens, int stdin, int stdout);
/* => call open file  => dup2 */
void	check_redir(t_tokens *tokens, int stdin, int stdout, int i);

/* execute.c */
int		execute(t_tokens *tokens, char **env, int pipe_num);

/* pipex.c */
void	here_doc(char **av, char **envp, int outfile_fd);
void	pipex(int ac, char **av, char **envp);

/* utils.c */
void	wait_children(int num_of_children);
void	exec(char *av, char **envp);
char	**find_path(char **envp);
int		open_file(char *file, int flag);

#endif