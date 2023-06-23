/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation_ortho.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:43:53 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/17 17:48:20 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_calculate_vertical(t_matrix *mat, int i, int j)
{
	mat->coords.x0 = mat->point[i][j].iso_x;
	mat->coords.y0 = mat->point[i][j].iso_y;
	mat->coords.x1 = mat->point[i + 1][j].iso_x;
	mat->coords.y1 = mat->point[i + 1][j].iso_y;
	ft_bresenham(mat->data, mat->coords, mat->color_start, \
		mat->color_end);
}

static void	ft_calculate_horizontal(t_matrix *mat, int i, int j)
{
	mat->coords.x0 = mat->point[i][j].iso_x;
	mat->coords.y0 = mat->point[i][j].iso_y;
	mat->coords.x1 = mat->point[i][j + 1].iso_x;
	mat->coords.y1 = mat->point[i][j + 1].iso_y;
	ft_bresenham(mat->data, mat->coords, mat->color_start, \
		mat->color_end);
}

void	ft_vertical(t_matrix *mat, int i, int j)
{
	ft_calculate_point(mat, i + 1, j);
	ft_calculate_vertical(mat, i, j);
}

void	ft_horizontal(t_matrix *mat, int i, int j)
{
	ft_calculate_point(mat, i, j + 1);
	ft_calculate_horizontal(mat, i, j);
}
