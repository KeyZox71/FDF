/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:11:59 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/15 05:51:22 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_read_error(char **buf, char *res)
{
	free(*buf);
	*buf = NULL;
	if (res[0] != 0)
		return (res);
	free(res);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*res;
	ssize_t		bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	res = ft_calloc(1, 1);
	while (buf[fd] && res)
	{
		res = ft_strjoin(res, buf[fd]);
		if (!res)
			return (NULL);
		if (check_line(res, buf[fd]))
			return (res);
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_read < 1)
			return (ft_read_error(&buf[fd], res));
		buf[fd][bytes_read] = 0;
	}
	return (NULL);
}
