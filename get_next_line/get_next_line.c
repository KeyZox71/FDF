/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:11:59 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/08 18:17:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	check_line(char *res, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
	{
		i++;
		while (res[i])
		{
			buf[j] = res[i];
			i++;
			j++;
		}
		buf[j] = 0;
		res[i - j] = 0;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;
	ssize_t		bytes_read;

	res = ft_calloc(1, 1);
	if (!buf)
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (buf && res)
	{
		res = ft_strjoin(res, buf);
		if (check_line(res, buf))
			return (res);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			free(buf);
			buf = NULL;
			if (res[0] != 0)
				return (res);
			free(res);
			return (NULL);
		}
		buf[bytes_read] = 0;
	}
	return (NULL);
}

/*#include <unistd.h>
void	ft_putstr(char	*str){if (str == NULL){return ;}int i = 0;while(str[i]){write(1, &str[i], 1);i++;}}
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*ln;
	int		fd;
	fd = open("test.txt", O_RDONLY);
	while (ln)
	{
		ln = get_next_line(fd);
		ft_putstr(ln);
		free(ln);
	}
	close(fd);
}*/
