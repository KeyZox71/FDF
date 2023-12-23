/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 05:19:39 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/23 08:29:30 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

void	ft_putstr(char	*s){int	i = 0;while(s[i]){write(1, &s[i], 1);i++;}}

size_t	ft_countline_fd(int fd)
{
	size_t	i;
	ssize_t	rd;
	size_t	count;
	char	*buf;

	i = 0;
	count = 1;
	buf = ft_calloc(1, 1);
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

size_t	ft_countline(char **map)
{
	size_t	i;

	while (map[i])
		i++;
	return (i);
}

int	ft_read_map(int fd, char **map)
{
	size_t	i;

	i = 0;
	while (map[i] && i <= ULONG_MAX)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	if (i == 0 && map[i] == NULL)
		return (-1);
	close(fd);
	map[i + 1] = NULL;
	return (i);
}

char	**ft_getmap(const char	*file)
{
	char	**map;
	int		fd;
	int		line_nb;

	printf("mais çá fait quelque chose au moins\n");
	fd = open(file, O_RDONLY);
	printf("file opened");
	line_nb = ft_countline_fd(fd);
	close(fd);
	map = ft_calloc(sizeof(char), line_nb);
	printf("linenb %d", line_nb);
	fd = open(file, O_RDONLY);
	ft_read_map(fd, map);
	return (map);
}

t_map	ft_split_height_color(char *tmp)
{
	t_map	height_color;
	int		i;

	height_color.y = ft_atoi(tmp);
	while (tmp[i] && tmp[i] != ',')
		i++;
	if (tmp[i] == ',')
	{
		i++;
		height_color.color = ft_strdup(&tmp[i]);
		return (height_color);
	}
	else
	{
		height_color.color = ft_strdup("0xFFFFFF");
		return (height_color);
	}
}

t_map	**ft_parse_map(char	**mapfile) 
{
	int		z;
	int		x;
	int		line_count;
	char	**tmp;
	t_map	**parsed_map;

	z = 0;
	line_count = ft_countline(mapfile);
	parsed_map = ft_calloc(sizeof(t_map), line_count);
	while (mapfile[z])
	{
		tmp = ft_split(mapfile[z], 32);
		x = 0;
		while (tmp[x])
		{
			parsed_map[z][x] = ft_split_height_color(tmp[x]);
			x++;
		}
	}
	return (parsed_map);
}

int	main(int ac, char **av)
{
	char	**map;
	int		i = 0;
	printf("%s", av[1]);
	map = ft_getmap(av[1]);
	(void)ac;
	ft_putstr("map read");
	while (map[i])
	{
		ft_putstr(map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}

//cc maps_reader.c fdf.h get_next_line/get_next_line.c get_next_line/get_next_line.h get_next_line/get_next_line_utils.c libft/libft.a 