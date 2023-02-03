/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:04:05 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/03 15:29:47 by nakoo            ###   ########.fr       */
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

# define FAILURE 0
# define SUCCESS 1

/* cd.c */

/* echo.c */

/* env.c */

/* exit.c */

/* export.c */

/* pwd.c */
void	pwd(char **env);

/* unset.c */

#endif