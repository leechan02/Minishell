/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:04:05 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/12 15:43:34 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/includes/libft.h"
# include "../srcs/pipex/pipex.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

# define NL 0
# define NO_NL 1

# define NO_EQUAL 0
# define EQUAL 1

void	ft_export(char **token, char **env);
void	ft_unset(char **token, char **env);
void	ft_cd(char *path, char **env);
void	ft_echo(char **token, int fd);
void	ft_pwd(char **envp);
void	ft_env(char **env);
void	ft_exit(void);

#endif