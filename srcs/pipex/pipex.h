/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:55 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/10 18:32:42 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"

enum e_flag {
	READ,
	WRITE,
	HERE_DOC
};

/* pipex.c */
void	pipex(char **av, char **envp, int *tmp_pipe, int outfile_fd);
void	here_doc(char **av, char **envp, int outfile_fd);
void	multiple_pipex(int ac, char **av, char **envp);

/* utils.c */
void	wait_children(int num_of_children);
void	exec(char *av, char **envp);
char	**find_path(char **envp);
int		open_file(char *file, int flag);

#endif