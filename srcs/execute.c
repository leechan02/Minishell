/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/09 19:47:23 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/* token struct */
typedef struct s_tokens {
	char	**token;
	int		*redirection;
}	t_tokens;

void	execute(t_tokens **tok, char **env)
{
	/* pipe 기준으로 t_tokens가 들어온다. */
	/* 1. token[i]부터 ->redirecion 처리, T/F도 판별 */
	/* 2. cmd 판별(builtin or not), To handle error case */
	/* 3. pipe ? */
	/* 4. pipe 병렬 처리 */
}
