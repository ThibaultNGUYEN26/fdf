/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:35:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/19 20:20:26 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init(t_matrix *mat, char *argv[])
{
	ft_init_data(mat);
	ft_printf(GREEN "\n[INFO]" WHITE " Opening map : "BLUE"'%s'\n\n" \
		EOC, argv[1]);
	ft_printf(GREEN"[COMMANDS]\n"WHITE \
		"  ● Enter              : "BLUE"Orthogonal view\n"WHITE \
		"  ● C                  : "BLUE"Change colors\n"WHITE \
		"  ● R                  : "BLUE"Reset colors\n"WHITE \
		"  ● Mouse wheel        : "BLUE"Zoom in/out\n"WHITE \
		"  ● Arrows             : "BLUE"Move render\n"WHITE \
		"  ● W/A/S/D/Left click : "BLUE"Rotate view\n"WHITE \
		"  ● -/+                : "BLUE"Change 3D height\n"WHITE \
		"  ● Escape             : "BLUE"Close window\n\n"EOC);
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
