/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 05:19:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/04 16:22:01 by adjoly           ###   ########.fr       */
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

t_map	ft_split_height_color(char *tmp)
{
	t_map	height_color;
	int		i;

	height_color.y = ft_atoi(tmp);
	while (tmp[i] && tmp[i] != ',')
		i++;
	if (tmp[i] == ',')
		height_color.color = ft_strdup(&tmp[i + 1]);
	else
		height_color.color = ft_strdup("0xFFFFFF");
	return (height_color);
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

size_t	ft_countline(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_map	**ft_parse_map(char	**mapfile, size_t line_count)
{
	int		z;
	int		x;
	char	**tmp;
	t_map	**parsed_map;
	size_t	i;

	z = 0;
	parsed_map = ft_calloc(sizeof(t_map *), line_count);
	while (mapfile[z])
	{
		tmp = ft_split(mapfile[z], 32);
		i = ft_countline(tmp);
		parsed_map[z] = ft_calloc(i, sizeof(t_map *));
		x = 0;
		while (tmp[x])
		{
			parsed_map[z][x] = ft_split_height_color(tmp[x]);
			x++;
		}
		parsed_map[z][x] = NULL;
		z++;
	}
	parsed_map[z] = NULL;
	return (parsed_map);
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

t_map	**ft_getmap(char *file)
{
	t_map	**map_parsed;
	char	**map;
	int		fd;
	size_t	line_nb;

	fd = open(file, O_RDONLY);
	line_nb = ft_countline_fd(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	map = ft_read_map(fd, line_nb);
	close(fd);
	map_parsed = ft_parse_map(map, line_nb);
	ft_free((void **)map);
	return (map_parsed);
}

int	main(int ac, char **av)
{
	t_map	**map;
	int		i = 0;
	char	*file_name;

	file_name = ft_strdup(av[1]);
	map = ft_getmap(file_name);
	(void)ac;
	ft_putstr("map read\n");
	while (map[i])
	{
		ft_printf("%s", map[i]->color);
		ft_putchar('\n');
		ft_putnbr(map[i]->y);
		ft_putchar('\n');
		i++;
	}
	ft_free((void **)map);
	return(0);
}

//cc maps_reader.c fdf.h get_next_line/get_next_line.c get_next_line/get_next_line.h get_next_line/get_next_line_utils.c libft/libft.a 