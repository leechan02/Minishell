/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:55 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/23 11:33:23 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

void	error(int return_value);
int		openfile(char *filename, int fd);
void	exec(char *cmd, char **env);
void	pipex(char *cmd1, char *cmd2, char **env);
int		main(int ac, char **av, char **env);
#endif