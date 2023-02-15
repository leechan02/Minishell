/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/15 14:10:50 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
	copy = ft_strdup(ft_strfind(env, "OLDPWD=") + 7);
	pwd = getcwd(NULL, 0);
	ft_strlcpy(oldpwd, pwd, ft_strlen(pwd) + 1);
	free(pwd);
	if (token[i + 1] == NULL || token[i + 1][0] == '~')
		pwd = ft_strfind(env, "HOME=") + 5;
	else if (token[i + 1][0] == '-')
	{
		printf("%s\n", copy);
		return (free(copy), chdir(copy));
	}
	else
		pwd = token[i + 1];
	chdir(pwd);
	ft_strlcpy(ft_strfind(env, "PWD=") + 4, pwd, ft_strlen(pwd) + 1);
	return (TRUE);
}
