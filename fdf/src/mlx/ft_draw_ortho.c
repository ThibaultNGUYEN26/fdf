/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ortho.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:27:27 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/17 17:47:46 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_calculate_point(t_matrix *mat, int i, int j)
{
	mat->point[i][j].iso_x = j * mat->coords.case_size / TEST + mat->coords.xo;
	mat->point[i][j].iso_y = i * mat->coords.case_size / TEST + mat->coords.yo;
}

void	ft_draw_ortho(t_matrix *mat)
{
	int	i;
	int	j;

	mlx_clear_window(mat->data->mlx, mat->data->win);
	ft_draw_background(mat);
	i = -1;
	while (++i < mat->rows)
	{
		j = -1;
		while (++j < mat->cols)
		{
			ft_calculate_point(mat, i, j);
			if (i + 1 < mat->rows)
			{
				ft_define_colors_vertical(mat, i, j);
				ft_vertical(mat, i, j);
			}
			if (j + 1 < mat->cols)
			{
				ft_define_colors_horizontal(mat, i, j);
				ft_horizontal(mat, i, j);
			}
		}
	}
}
