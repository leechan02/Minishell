/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:53 by euiclee           #+#    #+#             */
/*   Updated: 2023/02/20 09:42:41 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_tokens{
	char	**token;
	int		*redir;
}t_tokens;

int	g_exit;

/* main */
void	free_all(t_tokens *tokens);
#endif