/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:55 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/14 15:27:12 by euiclee          ###   ########.fr       */
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
void	here_doc(char **av, char **envp, int outfile_fd);
void	pipex(int ac, char **av, char **envp);

/* utils.c */
void	wait_children(int num_of_children);
void	exec(char *av, char **envp);
char	**find_path(char **envp);
int		open_file(char *file, int flag);

#endif