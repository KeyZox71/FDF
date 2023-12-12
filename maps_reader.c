/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 05:19:39 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/12 11:17:13 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_countline_fd(int fd)
{
	size_t	i;
	ssize_t	rd;
	size_t	count;
	char	*buf;

	i = 0;
	count = 1;
	while (i <= ULONG_MAX)
	{
		rd = read(fd, buf, 1);
		if (rd == -1)
			break ;
		else if (buf[0] == '\n')
			count++;
		i++;
	}
	if (i == 0)
		return (-1);
	return (count);
}

int	ft_read_map(int fd, char **map)
{
	size_t	i;

	while (map[i] && i <= ULONG_MAX)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	if (i == 0 && map[i] == NULL)
		return (-1);
	close(fd);
	return (i);
}


char	**ft_getmap(char	*file)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	map = ft_calloc(sizeof(char), ft_countline_fd(fd));
	close(fd);
	fd = open(file, O_RDONLY);
	ft_read_map(fd, map);
	return (map);
}
