/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/20 19:58:47 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	error_msg(int expression, char *msg)
{
	if (expression == FALSE)
	{
		perror(msg);
		return (FALSE);
	}
	return (TRUE);
}

static void	move_home_dir(char **env)
{
	char	*pwd;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "HOME=", 5) != 0)
		i++;
	pwd = &env[i][5];
	error_msg(chdir(pwd) == 0, "cd ");
}

static void	move_previous_dir(char *copy)
{
	if (error_msg(chdir(copy) == 0, "cd ") == TRUE)
		printf("%s\n", copy);
}

static void	move_token_dir(char *pwd)
{
	int	i;

	i = 0;
	error_msg(chdir(pwd) == 0, "cd ");
	free(pwd);
}

int	ft_cd(char **tok, char **env)
{
	char	*oldpwd;
	char	*copy;
	char	*pwd;
	int		i;

	i = -1;
	while (ft_strcmp(tok[++i], "cd") != 0)
		;
	oldpwd = ft_strfind(env, "OLDPWD");
	pwd = getcwd(NULL, 0);
	copy = ft_strdup(oldpwd);
	free(pwd);
	if (tok[i + 1] == NULL || (tok[i + 1][0] == '~' && tok[i + 1][1] == '\0'))
		move_home_dir(env);
	else if (tok[i + 1][0] == '-')
		move_previous_dir(copy);
	else if (tok[i + 1] != NULL)
	{
		pwd = ft_strdup(token[i + 1]);
		move_token_dir(pwd);
		free(pwd);
	}
	return (free(copy), TRUE);
}
