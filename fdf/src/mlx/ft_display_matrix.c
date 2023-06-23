/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:24:45 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/21 17:10:57 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	calculate_midpoints(t_matrix *mat)
{
	int	i;
	int	j;

	mat->size.west = INT_MAX;
	mat->size.east = INT_MIN;
	mat->size.north = INT_MAX;
	mat->size.south = INT_MIN;
	i = -1;
	while (++i < mat->rows)
	{
		j = -1;
		while (++j < mat->cols)
		{
			if (mat->point[i][j].iso_x < mat->size.west)
				mat->size.west = mat->point[i][j].iso_x;
			if (mat->point[i][j].iso_x > mat->size.east)
				mat->size.east = mat->point[i][j].iso_x;
			if (mat->point[i][j].iso_y < mat->size.north)
				mat->size.north = mat->point[i][j].iso_y;
			if (mat->point[i][j].iso_y > mat->size.south)
				mat->size.south = mat->point[i][j].iso_y;
		}
	}
	mat->size.mid_x = (mat->size.east + mat->size.west) / 2.0;
	mat->size.mid_y = (mat->size.south + mat->size.north) / 2.0;
}

void	ft_draw(t_matrix *mat)
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
			mat->point[i][j].z = mat->matrix[i][j];
			ft_angle_calculation(mat, i, j);
			if (i + 1 < mat->rows)
				ft_check_vertical(mat, i, j);
			if (j + 1 < mat->cols)
				ft_check_horizontal(mat, i, j);
		}
	}
	calculate_midpoints(mat);
}

static void	ft_define_height(t_matrix *mat, int max, int min)
{
	if (ft_strstr(mat->map, "t1.fdf") != NULL || \
		ft_strstr(mat->map, "t2.fdf"))
		mat->c.height = 0.45;
	else if (max >= 30 || min <= -30)
		mat->c.height = 0.05;
	else if (max >= 10 || min <= -10)
		mat->c.height = 0.1;
	else
		mat->c.height = 1;
}

static void	ft_height(t_matrix *mat)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = INT_MIN;
	min = INT_MAX;
	i = -1;
	while (++i < mat->rows)
	{
		j = -1;
		while (++j < mat->cols)
		{
			if (i + 1 < mat->rows)
			{
				if (mat->matrix[i + 1][j] > mat->matrix[i][j] &&
					mat->matrix[i + 1][j] > max)
					max = mat->matrix[i + 1][j];
				if (mat->matrix[i + 1][j] < mat->matrix[i][j] &&
					mat->matrix[i + 1][j] < min)
					min = mat->matrix[i + 1][j];
			}
		}
	}
	ft_define_height(mat, max, min);
}

void	ft_display_matrix(t_matrix *mat)
{
	ft_height(mat);
	while (mat->size.dist_ver < HEIGHT - 30 || mat->size.dist_hor < WIDTH - 30)
	{
		ft_adjust_size(mat);
		if (mat->size.dist_ver >= HEIGHT - 30
			|| mat->size.dist_hor >= WIDTH - 30)
		{
			mat->coords.case_size--;
			break ;
		}
		mat->coords.xo = CENTER_X - mat->size.mid_hor;
		mat->coords.yo = CENTER_Y - mat->size.mid_ver;
		mat->coords.case_size++;
	}
	ft_draw(mat);
}
