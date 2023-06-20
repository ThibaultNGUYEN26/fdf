/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:41:25 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 16:33:09 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_func_draw(t_matrix *mat)
{
	if (mat->ortho == 0)
		ft_draw(mat);
	else
		ft_draw_ortho(mat);
	mlx_put_image_to_window(mat->data->mlx, mat->data->win, mat->data->img, \
		0, 0);
}
