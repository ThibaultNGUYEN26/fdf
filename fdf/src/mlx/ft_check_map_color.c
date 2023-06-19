/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:30:50 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/19 20:04:06 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_check_color_ver(t_matrix *mat, int i, int j)
{
	if (ft_strcmp("test_maps/42.fdf", mat->map) == 0 && mat->color_switch == 0)
	{
		ft_the_map_vertical(mat, i, j);
		return (1);
	}
	else if (mat->color_switch == 1)
	{
		if (mat->key == 'C')
		{
			mat->color[i][j] *= 90;
			mat->color[i + 1][j] *= 90;
			mat->color[i][j] += 25;
			mat->color[i + 1][j] += 25;
			if (mat->color[i][j] >= 1284376756)
				mat->color[i][j] = 45545 + j + i;
			if (mat->color[i + 1][j] >= 1284376756)
				mat->color[i + 1][j] = 45545 + j + i;
		}
		mat->color_start = mat->color[i][j];
		mat->color_end = mat->color[i][j];
		return (1);
	}
	return (0);
}

int	ft_check_color_hor(t_matrix *mat, int i, int j)
{
	if (ft_strcmp("test_maps/42.fdf", mat->map) == 0 && mat->color_switch == 0)
	{
		ft_the_map_horizontal(mat, i, j);
		return (1);
	}
	else if (mat->color_switch == 1)
	{
		mat->color_start = mat->color[i][j];
		mat->color_end = mat->color[i][j];
		return (1);
	}
	return (0);
}
