/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/12 16:42:50 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	check_redirection(char **token)
{
	int	fd;
	fd = open_file(*file, flag)
	/* dup2 호출 */
}

int	execute(t_tokens *tokens, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		i;
	
	/* 1. token이 1개보다 많다면(pipe를 기준으로 나눴기 때문) */
	/* 2. default로 STDOUT을 pipe로 연결 */
	/* 3. token[i]부터 ->redirecion 처리, T/F도 판별 */
	/* 4. cmd 판별(builtin or not), To handle error case */
	/* 5. pipe ? */
	/* 6. pipe 병렬 처리 */
	i = 1;
	while (i < tokens)
		pid = fork();
	/* 마지막 token - 1 까지만 반복문에 들어간다. */
	while (tokens->token[i + 1] != NULL)
	{
		/* | 뒤에 아무것도 오지 않는 경우 */
		if (token->token[i] == NULL)
			return (FAIL);
		fd = pipex(tokens->token[i], env, fd);
		check_redirection(tokens->token[i]);
		
		i++;
	}
	return (SUCCESS);
}

/* 기본적으로 동적 할당된 구조체 포인터가 들어온다.
구조체 포인터의 멤버변수 이중 포인터에 접근해서 큰 반복문의 조건은 이중포인터로 
작은 반복문의 조건은 이중 포인터 속 포인터로 접근 
단순하게 생각해서 커맨드면 실행 시켜주고
리다이렉션이면 입/출력 스트림을 변경시켜준다. 
그리고나서 파이프에 넘겨준다. 
Q1. 토큰이 하나여도 자식 프로세스 실행 ? (일관된 코드 || 반복문 조건 성립 x)
*/