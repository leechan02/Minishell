/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:32:05 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/08 19:55:38 by euiclee          ###   ########.fr       */
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
int		get_end_with_len(char **loca, char **finish, char *origin, char **env);
char	*make_ret(char **loca, char *origin, char **env, char **finish);
char	*replace_env(char **loca, char *origin, char **env);
char	**check_env(char *line, char **env);
#endif