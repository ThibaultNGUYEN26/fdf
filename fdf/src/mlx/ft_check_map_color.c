/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:30:50 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 16:37:15 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_calculate_colors(t_matrix *mat, int i, int j)
{
	mat->color[i][j] *= 90;
	mat->color[i + 1][j] *= 90;
	mat->color[i][j] += 100;
	mat->color[i + 1][j] += 100;
	if (mat->color[i][j] >= INT_MAX - 500000000)
		mat->color[i][j] = 1000000 + j + i;
	if (mat->color[i + 1][j] >= INT_MAX - 500000000)
		mat->color[i + 1][j] = 1000000 + j + i;
}

int	ft_check_color_ver(t_matrix *mat, int i, int j)
{
	int	k;

	if (ft_strstr(mat->map, "42.fdf") != NULL && mat->color_switch == 0)
	{
		ft_the_map_vertical(mat, i, j);
		return (1);
	}
	else if (mat->color_switch == 1)
	{
		if (mat->key == 'C')
			ft_calculate_colors(mat, i, j);
		mat->color_start = mat->color[i][j];
		mat->color_end = mat->color[i][j];
		k = -1;
		while (++k < mat->rows)
			free(mat->color[k]);
		free(mat->color);
		return (1);
	}
	return (0);
}

int	ft_check_color_hor(t_matrix *mat, int i, int j)
{
	if (ft_strstr(mat->map, "42.fdf") != NULL && mat->color_switch == 0)
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
