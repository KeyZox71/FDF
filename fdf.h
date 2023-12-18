/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 05:10:42 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/18 14:18:16 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "MacroLibX/includes/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	int		y;
	char	*color;
}	j 	t_map;

int		ft_read_map(int fd, char **map);
size_t	ft_countline_fd(int fd);
char	**ft_getmap(char *file);

#endif