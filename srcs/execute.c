/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/02/14 14:02:27 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	is_builtin(t_tokens *tokens, char **env, int idx)
{
	int	j;

	j = 0;
	while (tokens->token + idx != NULL)
	{
		if (ft_strcmp(tokens->token[j], "export") == 0)
			return (ft_export(tokens->token + idx, env));
		else if (ft_strcmp(tokens->token[j], "unset") == 0)
			return (ft_unset(tokens->token + idx, env));
		else if (ft_strcmp(tokens->token[j], "cd") == 0)
			return (ft_cd(tokens->token + idx, env));
		else if (ft_strcmp(tokens->token[j], "echo") == 0)
			return (ft_echo(tokens->token + idx));
		else if (ft_strcmp(tokens->token[j], "pwd") == 0)
			return (ft_pwd(env));
		else if (ft_strcmp(tokens->token[j], "env") == 0)
			return (ft_env(env));
		else if (ft_strcmp(tokens->token[j], "exit") == 0)
			ft_exit(tokens->token + idx);
		j++;
	}
	return (FALSE);
}

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
	int		cnt;
	int		i;
	
	cnt = 0;
	while (tokens->token[cnt] != NULL)
		cnt++;
	if (cnt == 1 && is_builtin(tokens, env, 0) == TRUE)
		return (SUCCESS);
	i = 0;
	while (tokens->token[i] != NULL)
	{
		if (token->token[i] == NULL)
			return (FAIL);
		pid = fork();
		fd = pipex(tokens->token[i], env, fd);
		check_redirection(tokens->token[i]);
		i++;
	}
	wait_children(i);
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