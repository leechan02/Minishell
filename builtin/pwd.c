/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/02 14:40:52 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	pwd(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	printf("%s\n", envp[i] + 4);
}
