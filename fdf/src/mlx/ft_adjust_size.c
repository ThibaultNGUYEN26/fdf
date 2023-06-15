/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:29:43 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/12 16:49:20 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_find_max(int coords, int *max)
{
	if (coords > *max)
		*max = coords;
}

void	ft_find_min(int coords, int *min)
{
	if (coords < *min)
		*min = coords;
}

void	ft_calculation_size(t_matrix *mat, int i, int j)
{
	ft_find_max(mat->point[i][j].iso_x, &mat->size.east);
	ft_find_min(mat->point[i][j].iso_x, &mat->size.west);
	ft_find_max(mat->point[i][j].iso_y, &mat->size.south);
	ft_find_min(mat->point[i][j].iso_y, &mat->size.north);
	mat->size.mid_hor = (mat->size.east - mat->size.west) / 2 + mat->size.west;
	mat->size.mid_ver = (mat->size.south - mat->size.north) \
		/ 2 + mat->size.north;
}

void	ft_adjust_size(t_matrix *mat)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mat->rows)
	{
		j = -1;
		while (++j < mat->cols)
		{
			mat->point[i][j].z = mat->matrix[i][j];
			ft_angle_adjust(mat, i, j);
			ft_calculation_size(mat, i, j);
		}
	}
	mat->size.dist_ver = mat->size.south - mat->size.north;
	mat->size.dist_hor = mat->size.east - mat->size.west;
}
