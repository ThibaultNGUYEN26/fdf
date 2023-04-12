/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:35:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/12 20:30:54 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* 
x cos radian +
y sin radian - 
*/

void	draw_pixel(void *mlx, void *win, int x, int y)
{
	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}



int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF Project");
		draw_map(argv[1], &vars);
		ft_matrix(argv[1]);
		ft_read_map(argv[1]);
		mlx_hook(vars.win, 17, 0, ft_close_window, vars.mlx);
		mlx_hook(vars.win, 2, 0, ft_key_hook, vars.mlx);
		mlx_loop(vars.mlx);
	}
	return (0);
}
