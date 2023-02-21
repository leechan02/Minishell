/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:57:37 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/21 19:32:48 by nakoo            ###   ########.fr       */
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

enum e_status {
	SHELL,
	PARENT_EXECVE,
	CHILD_EXECVE,
	HEREDOC
};

typedef struct s_pipe
{
	int		cmd;
	int		old_fd[2];
	int		new_fd[2];
	pid_t	pid;
	char	**file_name;
}t_pipe;

/* builtin */
int		is_builtin(t_tokens tokens);
int		exec_builtin(t_tokens *tokens, char **dup_env);

/* redirect */
char	**replace_redir(t_tokens *tokens, int i);
int		exec_redir(t_tokens *tokens, int i, int flag);
int		find_redir(t_tokens *tokens, int new_fd, int token_nb, int cmd);
int		check_redir(t_tokens *tokens, int i);

/* execute.c */
int		only_process(t_tokens *tokens, char **env, int flag);
int		execute(t_tokens *tokens, char **env, int pipe_num);

/* here_doc */
char	**name_save(t_tokens *tokens);
char	**find_here_doc(t_tokens *tokens, int *flag);
int		save_filename(t_tokens *tokens, char **name, int *file_n, int i);
void	replace_here_doc(t_tokens *tokens, int i, int *file_n);
void	here_doc(t_tokens *tokens, int i, char *name, int *flag);

/* pipex.c */
void	file_delete(char **file_name);
void	pipex(int token_nb, t_tokens *tokens, char **env, int flag);

/* utils.c */
void	wait_children(int num_of_children);
void	exec(char **token, char **envp);
char	**find_path(char **envp);
int		open_file(char *file, int flag);

/* signal.c */
void	sigexit_handler(void);
void	sigint_handler1(int sig);
void	sigint_handler2(int sig);
void	setting_signal(int status);

#endif