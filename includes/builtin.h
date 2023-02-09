/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:04:05 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/09 09:40:16 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

# define NL 0
# define NO_NL 1

# define NO_EQUAL 0
# define EQUAL 1

void	ft_cd(char *path, char **env);
void	ft_echo(char **token);
void	ft_env(char **env);
void	ft_pwd(char **envp);
void	ft_exit(void);

/* export.c */
void	sort_ascii(int *sorted_idx, char **env);
void	ft_export(char *str, char **env);
void	print_export(char **env);
void	swap(int *a, int *b);

#endif