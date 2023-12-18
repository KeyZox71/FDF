/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 05:11:15 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/13 04:35:22 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(void	*param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_string_put(mlx->mlx, mlx->win, 40, 40, 0xFFFFFFFF, "Mais ou sont mes ;");
	return (0);
}



int	main(int ac, char **av)
{
	t_mlx	mlx;
	char	**map;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1280, 720, "My window");
	mlx_loop_hook(mlx.mlx, update, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	return (0);
}
