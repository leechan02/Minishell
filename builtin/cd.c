/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:03 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/02 14:27:17 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/* HOME path를 가져오기 위해 evnp 인자 필요 */
int	cd(char *path, char **envp)
{
	char	*cwd;

	cwd = (char *)malloc(sizeof(char) * 1024);
	if (cwd == NULL)
		/* error function */
	cwd = getcwd(cwd, sizeof(char) * 1024);
	if (cwd == NULL)
		/* error function - 실패 상황에 대해 고려해야할지 ? */
}
