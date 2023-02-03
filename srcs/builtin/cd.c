/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/03 19:50:04 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	cd(char *path, char **env)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = ft_strfind(env, "OLDPWD=") + 7;
	pwd = getcwd(NULL, 0);
	ft_strlcpy(oldpwd, pwd, ft_strlen(pwd));
	free(pwd);
	if (*path == '\0')
		pwd = ft_strfind(env, "HOME=") + 5;
	else
		pwd = path;
	chdir(pwd);
	ft_strlcpy(ft_strfind(env, "PWD=") + 4, pwd, ft_strlen(pwd));
	free(path);
}
