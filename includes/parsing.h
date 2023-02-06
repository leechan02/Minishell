/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:32:05 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/06 10:10:57 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

int		get_pipe(char *line);
int		until_pipe(char *line, int i);
void	parsing(char *line, char ***tokens, char **env);

#endif