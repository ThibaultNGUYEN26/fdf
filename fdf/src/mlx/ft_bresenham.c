/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:44:16 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/15 19:11:42 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_mlx_pixel_put(t_data *data, int *x_y, int color)
{
	char	*dst;

	if (x_y[0] >= 0 && x_y[0] < WIDTH && x_y[1] >= 0 && x_y[1] < HEIGHT)
	{
		dst = data->addr + (x_y[1] * data->line_length \
			+ x_y[0] * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static int	grad_color(t_colors col, int col_start, int col_end, double ratio)
{
	col.r_start = (col_start & 0xFF0000) >> 16;
	col.g_start = (col_start & 0x00FF00) >> 8;
	col.b_start = col_start & 0x0000FF;
	col.r_end = (col_end & 0xFF0000) >> 16;
	col.g_end = (col_end & 0x00FF00) >> 8;
	col.b_end = col_end & 0x0000FF;
	col.grad_red = col.r_start + ratio * (col.r_end - col.r_start);
	col.grad_green = col.g_start + ratio * (col.g_end - col.g_start);
	col.grad_blue = col.b_start + ratio * (col.b_end - col.b_start);
	return ((col.grad_red << 16) | (col.grad_green << 8) | col.grad_blue);
}

static void	ft_init(double *deltas, t_coords coords, double *error, int *steps)
{
	deltas[0] = abs(coords.x1 - coords.x0);
	deltas[1] = abs(coords.y1 - coords.y0);
	if (coords.x0 < coords.x1)
		steps[0] = 1;
	else
		steps[0] = -1;
	if (coords.y0 < coords.y1)
		steps[1] = 1;
	else
		steps[1] = -1;
	if (deltas[0] > deltas[1])
		error[0] = deltas[0] / 2.0;
	else
		error[0] = -deltas[1] / 2.0;
}

static void	ft_delta_check(double *error, double *deltas, int *steps, int *curr)
{
	if (error[1] > -deltas[0])
	{
		error[0] -= deltas[1];
		curr[0] += steps[0];
	}
	if (error[1] < deltas[1])
	{
		error[0] += deltas[0];
		curr[1] += steps[1];
	}
}

void	ft_bresenham(t_data *data, t_coords coords, int col_start, int col_end)
{
	double	deltas[2];
	int		steps[2];
	double	error[2];
	double	ratio;
	int		curr[2];

	ft_init(deltas, coords, error, steps);
	curr[0] = coords.x0;
	curr[1] = coords.y0;
	while (1)
	{
		ratio = (double)(curr[0] - coords.x0) / (double)(coords.x1 - coords.x0);
		ft_mlx_pixel_put(data, curr, \
			grad_color(data->col, col_end, col_start, ratio));
		if (curr[0] == coords.x1 && curr[1] == coords.y1)
			break ;
		error[1] = error[0];
		ft_delta_check(error, deltas, steps, curr);
	}
}
