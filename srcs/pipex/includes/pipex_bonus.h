/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:55 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/23 11:38:17 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define HEREDOC 2
# define ERROR "Wrong parameter\n"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

/*pipex_bonus*/
void	error(int return_value);
int		openfile(char *filename, int fd);
void	exec(char *cmd, char **env);
void	pipex(char **av, int ac, char **env);
int		main(int ac, char **av, char **env);

/*heredoc*/
void	here_doc(char **av, int fd[2]);
void	here_pipex(char **av, char **env, pid_t pid[2], int fd[2][2]);
#endif