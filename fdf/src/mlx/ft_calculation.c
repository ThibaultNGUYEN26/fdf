/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:28:42 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/15 18:48:47 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_horizontal_calculation(t_matrix *mat, int i, int j)
{
	mat->point[i + 1][j].z = mat->matrix[i + 1][j];
	ft_angle_calculation(mat, i + 1, j);
	mat->coords.x0 = mat->point[i][j].iso_x;
	mat->coords.y0 = mat->point[i][j].iso_y;
	mat->coords.x1 = mat->point[i + 1][j].iso_x;
	mat->coords.y1 = mat->point[i + 1][j].iso_y;
	ft_bresenham(mat->data, mat->coords, mat->color_start, mat->color_end);
}

void	ft_vertical_calculation(t_matrix *mat, int i, int j)
{
	mat->point[i][j + 1].z = mat->matrix[i][j + 1];
	ft_angle_calculation(mat, i, j + 1);
	mat->coords.x0 = mat->point[i][j].iso_x;
	mat->coords.y0 = mat->point[i][j].iso_y;
	mat->coords.x1 = mat->point[i][j + 1].iso_x;
	mat->coords.y1 = mat->point[i][j + 1].iso_y;
	ft_bresenham(mat->data, mat->coords, mat->color_start, mat->color_end);
}

void	ft_check_horizontal(t_matrix *mat, int i, int j)
{
	if (ft_strcmp("test_maps/42.fdf", mat->map) == 0)
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
	ft_horizontal_calculation(mat, i, j);
}

void	ft_check_vertical(t_matrix *mat, int i, int j)
{
	if (ft_strcmp("test_maps/42.fdf", mat->map) == 0)
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
	ft_vertical_calculation(mat, i, j);
}
