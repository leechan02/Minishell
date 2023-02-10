/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:04:05 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/09 15:47:14 by nakoo            ###   ########.fr       */
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
int		*sort_ascii(char **env);
void	print_export(char **env, int *sorted_idx, int sign);
void	ft_export(char **token, char **env);
void	swap(int *a, int *b);

/* unset.c */
int		get_del_idx(char *token, char **env, int *del_idx);
void	ft_unset(char **token, char **env);

#endif