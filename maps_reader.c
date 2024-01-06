/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 05:19:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/06 08:18:22 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "printf/ft_printf.h"

// void	ft_putstr(char	*s){int	i = 0;while(s[i]){write(1, &s[i], 1);i++;}}

void	ft_free(void **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

size_t	ft_countline_fd(int fd)
{
	size_t	i;
	ssize_t	rd;
	size_t	count;
	char	*buf;

	i = 0;
	count = 1;
	buf = ft_calloc(1, 1);
	while (i < ULONG_MAX)
	{
		rd = read(fd, buf, 1);
		if (rd == -1 || rd == 0)
			break ;
		else if (buf[0] == '\n')
			count++;
		i++;
	}
	free(buf);
	if (i == 0)
		return (-1);
	return (count);
}

char	**ft_read_map(int fd, size_t map_size)
{
	size_t	i;
	char	**map;

	i = 0;
	map = ft_calloc(sizeof(char *), map_size + 1);
	while (i < map_size)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	return (map);
}

t_map	**ft_get_map(char *file)
{
	t_map	**parsed_map;
	char	**map_read;
	int		fd;
	int		map_size;

	fd = open(file, O_RDONLY);
	map_size = ft_countline_fd(fd);
	close (fd);
	fd = open(file, O_RDONLY);
	map_read = ft_read_map(fd, map_size);
	close (fd);
	return (parsed_map);
}

int	main(int ac, char **av)
{
	return (0);
}
