/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:42:46 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/21 17:16:48 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char **s)
{
	if (*s)
		free(*s);
	*s = NULL;
	return (NULL);
}

char	*new_backup(char **backup, char *buf)
{
	char	*new_backup;
	size_t	backup_len;
	size_t	buf_len;

	backup_len = ft_strlen(*backup);
	buf_len = ft_strlen(buf);
	new_backup = (char *)ft_calloc(backup_len + buf_len + 1, sizeof(char));
	if (!new_backup)
		return (free_all(backup));
	ft_strlcat(new_backup, *backup, backup_len + buf_len + 1);
	ft_strlcat(new_backup, buf, backup_len + buf_len + 1);
	free_all(backup);
	return (new_backup);
}

char	*get_line(char **backup)
{
	char	*line;
	char	*line_end;

	if (ft_strchr(*backup, '\n'))
		line_end = ft_strchr(*backup, '\n') + 1;
	else
		line_end = ft_strchr(*backup, '\0');
	line = (char *)ft_calloc(line_end - *backup + 1, sizeof(char));
	if (!line)
		return (free_all(backup));
	ft_strlcat(line, *backup, line_end - *backup + 1);
	*backup[0] = '\0';
	*backup = new_backup(backup, line_end);
	return (line);
}

char	*read_line(int fd, char **backup)
{
	char	buf[2];
	int		byte;

	byte = 1;
	while (byte)
	{
		if (ft_strchr(*backup, '\n'))
			break ;
		byte = read(fd, buf, 1);
		if (byte < 0)
			return (free_all(backup));
		buf[byte] = '\0';
		*backup = new_backup(backup, buf);
		if (!backup || !*backup)
			return (free_all(backup));
	}
	if (byte == 0 && **backup == '\0')
		return (free_all(backup));
	return (get_line(backup));
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX + 1];

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	return (read_line(fd, &backup[fd]));
}
