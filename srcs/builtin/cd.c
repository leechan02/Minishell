/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/20 09:02:19 by euiclee          ###   ########.fr       */
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

	pwd = NULL;
	pwd = ft_strfind(env, "HOME=") + 5;
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
	pwd = getcwd(NULL, 0);
}

int	ft_cd(char **token, char **env)
{
	char	*oldpwd;
	char	*copy;
	char	*pwd;
	int		i;

	i = -1;
	while (ft_strcmp(token[++i], "cd") != 0)
		;
	oldpwd = ft_strfind(env, "OLDPWD=") + 7;
	copy = ft_strdup(oldpwd);
	pwd = getcwd(NULL, 0);
	ft_strlcpy(oldpwd, pwd, ft_strlen(pwd) + 1);
	free(pwd);
	if (token[i + 1] == NULL || token[i + 1][0] == '~')
		move_home_dir(env);
	else if (token[i + 1][0] == '-')
		move_previous_dir(copy);
	else if (token[i + 1] != NULL)
	{
		pwd = ft_strdup(token[i + 1]);
		move_token_dir(pwd);
		free(pwd);
	}
	return (free(copy), TRUE);
}
