/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhovsepy <mhovsepy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:12:47 by mhovsepy          #+#    #+#             */
/*   Updated: 2022/06/14 18:26:44 by mhovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*fill_line(char *line, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		len;

	len = 0;
	while (1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		buff[len] = 0;
		if (len == -1)
			return (0);
		if (!line)
			line = ft_strdup(buff);
		else
			line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n') || len == 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			line_len;
	char		*temp;
	char		*ret_line;

	line = fill_line(line, fd);
	if (!line)
		return (0);
	line_len = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n')) + 1;
	ret_line = ft_substr(line, 0, line_len);
	temp = line;
	line = ft_substr(line, line_len, ft_strlen(line) - line_len);
	free(temp);
	return (ret_line);
}

// int main()
// {
//     int fd1;
//     int fd2;

//     fd1 = open("test.txt", O_RDONLY);
//     printf("%s", get_next_line(fd1));
//     fd2 = open("test2.txt", O_RDONLY);
//     printf("%s", get_next_line(fd1));
//     printf("%s", get_next_line(fd2));
// }
