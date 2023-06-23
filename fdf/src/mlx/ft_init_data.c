/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:31:26 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/12 13:58:08 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_init_data(t_matrix *mat)
{
	mat->data->mlx = mlx_init();
	mat->data->win = mlx_new_window(mat->data->mlx, WIDTH, HEIGHT, \
		"FdF Project");
	mat->data->img = mlx_new_image(mat->data->mlx, WIDTH, HEIGHT);
	mat->data->addr = mlx_get_data_addr(mat->data->img, \
		&(mat->data->bits_per_pixel), &(mat->data->line_length), \
		&(mat->data->endian));
}
