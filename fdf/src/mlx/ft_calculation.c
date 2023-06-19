/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:28:42 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/19 19:22:19 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_vertical_calculation(t_matrix *mat, int i, int j)
{
	mat->point[i + 1][j].z = mat->matrix[i + 1][j];
	ft_angle_calculation(mat, i + 1, j);
	mat->coords.x0 = mat->point[i][j].iso_x;
	mat->coords.y0 = mat->point[i][j].iso_y;
	mat->coords.x1 = mat->point[i + 1][j].iso_x;
	mat->coords.y1 = mat->point[i + 1][j].iso_y;
	ft_bresenham(mat->data, mat->coords, mat->color_start, mat->color_end);
}

void	ft_horizontal_calculation(t_matrix *mat, int i, int j)
{
	mat->point[i][j + 1].z = mat->matrix[i][j + 1];
	ft_angle_calculation(mat, i, j + 1);
	mat->coords.x0 = mat->point[i][j].iso_x;
	mat->coords.y0 = mat->point[i][j].iso_y;
	mat->coords.x1 = mat->point[i][j + 1].iso_x;
	mat->coords.y1 = mat->point[i][j + 1].iso_y;
	ft_bresenham(mat->data, mat->coords, mat->color_start, mat->color_end);
}

void	ft_check_vertical(t_matrix *mat, int i, int j)
{
	ft_define_colors_vertical(mat, i, j);
	ft_vertical_calculation(mat, i, j);
}

void	ft_check_horizontal(t_matrix *mat, int i, int j)
{
	ft_define_colors_horizontal(mat, i, j);
	ft_horizontal_calculation(mat, i, j);
}
