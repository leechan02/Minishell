/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:32:05 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/14 09:37:54 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

/*parse*/
int		get_pipe(char *line);
int		until_pipe(char *line);
int		parsing(char *line, t_tokens **tokens, char **env);

/*parse_split*/
int		cnt_tokens(char *token);
int		until_sep(char **token);
int		is_spaquot(char **token, int qut, int db_qut);
int		is_redirection(char **token, int qut, int db_qut, int *len);
char	**split_token(char *token);

/*pase_env*/
int		get_end_with_len(char **loca, char **finish, char *origin, char **env);
char	*make_ret(char **loca, char *origin, char **env, char **finish);
char	*replace_env(char **loca, char *origin, char **env);
void	check_env(t_tokens *tokens, char **env);

/*parse_redir*/
void	is_redir(t_tokens **tok, int idx, int token_num);

/*parse_quote*/
void	check_quote(t_tokens *tokens);
#endif