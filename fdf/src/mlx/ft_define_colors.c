/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:14:18 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/21 17:27:17 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_the_map_vertical(t_matrix *mat, int i, int j)
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

void	ft_the_map_horizontal(t_matrix *mat, int i, int j)
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
	if (ft_check_color_ver(mat, i, j) == 0)
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
	if (ft_check_color_hor(mat, i, j) == 0)
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

void	ft_switch_color(t_matrix *mat)
{
	mat->key = 'C';
	mat->color_switch = 1;
}
