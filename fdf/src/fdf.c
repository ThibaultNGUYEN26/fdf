/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:35:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 20:31:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_matrix	*mat;

	if (argc == 2)
	{
		ft_printf(GREEN "\n[INFO]" WHITE " Initialization of MLX window.\n\n" EOC);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FdF Project");
		vars.img = mlx_new_image(vars.mlx, WIDTH - 10, HEIGHT - 10);
		mat = ft_init_matrix(argv[1]);
		mlx_hook(vars.win, 17, 0, ft_close_window, vars.mlx);
		mlx_hook(vars.win, 2, 0, ft_key_hook, vars.mlx);
		ft_display_matrix(mat, vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
