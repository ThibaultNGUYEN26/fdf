/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:35:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/15 19:58:40 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init(t_matrix *mat, char *argv[])
{
	ft_init_data(mat);
	ft_printf(GREEN "\n[INFO]" WHITE " Opening map : '%s'\n\n" EOC, argv[1]);
	ft_init_size_render(mat);
	ft_display_matrix(mat);
}

int	main(int argc, char *argv[])
{	
	t_data		*data;
	t_matrix	*mat;

	data = NULL;
	if (argc == 2)
	{
		ft_printf(GREEN "[INFO]" WHITE " Initialization of MLX window.\n" EOC);
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		mat = ft_init_matrix(argv[1]);
		mat->data = data;
		ft_init(mat, argv);
		mlx_hook(mat->data->win, 17, 0, ft_close_window, mat->data->mlx);
		mlx_hook(mat->data->win, 2, 0, ft_key_hook, mat);
		mlx_hook(mat->data->win, 4, 0, wheel_event, mat);
		mlx_hook(mat->data->win, 5, 0, mouse_release_hook, mat);
		mlx_hook(mat->data->win, 6, 1L << 6, mouse_movement_hook, mat);
		mlx_put_image_to_window(mat->data->mlx, mat->data->win, mat->data->img, \
			0, 0);
		mlx_loop(mat->data->mlx);
	}
	return (0);
}
