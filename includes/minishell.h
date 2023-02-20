/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:53 by euiclee           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/20 16:55:27 by nakoo            ###   ########.fr       */
=======
/*   Updated: 2023/02/20 09:42:41 by euiclee          ###   ########.fr       */
>>>>>>> 4fcdbceedde43a50f49d58a318105bbd59773bbc
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