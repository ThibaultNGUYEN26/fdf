/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:54:47 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/15 19:54:58 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_draw_background(t_matrix *mat)
{
	int	i;
	int	j;
	int	x_y[2];

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			x_y[0] = i;
			x_y[1] = j;
			ft_mlx_pixel_put(mat->data, x_y, 0x000000);
		}
	}
}
