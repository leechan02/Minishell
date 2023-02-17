/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/17 19:24:14 by nakoo            ###   ########.fr       */
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
		pwd = ft_strfind(env, "HOME=") + 5;
	else if (token[i + 1][0] == '-')
	{
		if (error_msg(chdir(copy) == 0, "cd ") == TRUE)
			printf("%s\n", copy);
		return (free(copy), TRUE);
	}
	else if (token[i + 1] != NULL)
		pwd = token[i + 1];
	error_msg(chdir(pwd) == 0, "cd ");
	pwd = getcwd(NULL, 0);
	/* seg error ft_strlcpy(ft_strfind(env, "PWD=") + 4, pwd, ft_strlen(pwd) + 1); */
	return (free(pwd), TRUE);
}
