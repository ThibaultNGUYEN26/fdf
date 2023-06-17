/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:14:18 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/17 17:50:23 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_the_map_vertical(t_matrix *mat, int i, int j)
{
	if (mat->matrix[i][j] > mat->matrix[i + 1][j])
	{
		mat->color_start = 0xFFFF00;
		mat->color_end = 0xFFA500;
	}
	else if (mat->matrix[i][j] < mat->matrix[i + 1][j])
	{
		mat->color_start = 0xFFA500;
		mat->color_end = 0xFFFF00;
	}
	else if (mat->matrix[i][j] == 0 && mat->matrix[i + 1][j] == 0)
	{
		mat->color_start = 0xFFFFFF;
		mat->color_end = 0xFFFFFF;
	}
	else
	{
		mat->color_start = 0xFF00FF;
		mat->color_end = 0xFF00FF;
	}
}

static void	ft_the_map_horizontal(t_matrix *mat, int i, int j)
{
	if (mat->matrix[i][j] > mat->matrix[i][j + 1])
	{
		mat->color_start = 0xFFFF00;
		mat->color_end = 0xFFA500;
	}
	else if (mat->matrix[i][j] < mat->matrix[i][j + 1])
	{
		mat->color_start = 0xFFA500;
		mat->color_end = 0xFFFF00;
	}
	else if (mat->matrix[i][j] == 0 && mat->matrix[i][j + 1] == 0)
	{
		mat->color_start = 0xFFFFFF;
		mat->color_end = 0xFFFFFF;
	}
	else
	{
		mat->color_start = 0xFF00FF;
		mat->color_end = 0xFF00FF;
	}
}

void	ft_define_colors_vertical(t_matrix *mat, int i, int j)
{
	if (ft_strcmp("test_maps/42.fdf", mat->map) == 0)
		ft_the_map_vertical(mat, i, j);
	else
	{
		if (mat->matrix[i][j] > mat->matrix[i + 1][j])
		{
			mat->color_start = mat->point[i + 1][j].color;
			mat->color_end = mat->point[i][j].color;
		}
		else if (mat->matrix[i][j] < mat->matrix[i + 1][j])
		{
			mat->color_start = mat->point[i][j].color;
			mat->color_end = mat->point[i + 1][j].color;
		}
		else if (mat->matrix[i][j] == mat->matrix[i + 1][j])
		{
			mat->color_start = mat->point[i][j].color;
			mat->color_end = mat->point[i][j].color;
		}
	}
}

void	ft_define_colors_horizontal(t_matrix *mat, int i, int j)
{
	if (ft_strcmp("test_maps/42.fdf", mat->map) == 0)
		ft_the_map_horizontal(mat, i, j);
	else
	{
		if (mat->matrix[i][j] > mat->matrix[i][j + 1])
		{
			mat->color_start = mat->point[i][j + 1].color;
			mat->color_end = mat->point[i][j].color;
		}
		else if (mat->matrix[i][j] < mat->matrix[i][j + 1])
		{
			mat->color_start = mat->point[i][j].color;
			mat->color_end = mat->point[i][j + 1].color;
		}
		else if (mat->matrix[i][j] == mat->matrix[i][j + 1])
		{
			mat->color_start = mat->point[i][j].color;
			mat->color_end = mat->point[i][j].color;
		}
	}
}
