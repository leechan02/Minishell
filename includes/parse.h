/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:32:05 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/07 09:42:49 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

/*parse*/
int		get_pipe(char *line);
int		until_pipe(char *line, int i);
void	parsing(char *line, char ***tokens, char **env);

/*pase_env*/
int		get_len(char *line, char *env);
char	*get_env(char *line);
char	**check_env(char *line, char **env);
char	*replace_env(char *line, char *env, char *env_name);
#endif