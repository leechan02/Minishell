/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:57:37 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/15 14:57:47 by nakoo            ###   ########.fr       */
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
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef void	(*t_sig)(int);

enum e_flag {
	READ,
	WRITE,
	HERE_DOC
};

enum e_redir {
	IN,
	OUT,
	HERE,
	APPEND
};

/* builtin */
int		is_builtin(t_tokens tokens);
int		exec_builtin(t_tokens *tokens, char **env);

/* redirect */
char	**replace_redir(t_tokens *tokens, int i);
int		exec_redir(t_tokens *tokens, int i, int flag);
int		find_redir(t_tokens *tokens);
int		check_redir(t_tokens *tokens, int i);

/* execute.c */
int		only_process(t_tokens *tokens, char **env);
int		execute(t_tokens *tokens, char **env, int pipe_num);

/* pipex.c */
// void	here_doc(char **av, char **envp, int outfile_fd);
void	pipex(int token_nb, t_tokens *tokens, char **env);

/* utils.c */
void	wait_children(int num_of_children);
void	exec(char **token, char **envp);
char	**find_path(char **envp);
int		open_file(char *file, int flag);

/* signal.c */
void	sigexit_handler(void);
void	signal_handler(int sig);

#endif