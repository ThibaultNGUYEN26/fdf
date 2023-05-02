/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:24:45 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 21:04:54 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_put_pixel(t_vars vars, int x, int y, int color)
{
	mlx_pixel_put(vars.mlx, vars.win, y, x, color);
}

void	ft_bresenham_line(t_vars vars, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1-x0);
	int dy = abs(y1-y0);
	int sx = x0<x1 ? 1 : -1;
	int sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2;
	int e2;

	while (1)
	{
		ft_put_pixel(vars, x0, y0, color);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	ft_display_matrix(t_matrix *mat, t_vars vars)
{
	int	i;
	int	j;
	int	x;
	int	y;
	
	x = 280;
	y = 200;
	i = -1;
	while (++i < mat->rows)
	{
		j = -1;
		while (++j < mat->cols)
		{
			if (mat->matrix[i][j] > 0)
				ft_put_pixel(vars, i * 30 + y, j * 30 + x, 0xFF0000);
			else
				ft_put_pixel(vars, i * 30 + y, j * 30 + x, 0xFFFFFF);
			if (i + 1 < mat->rows && mat->matrix[i + 1][j] > 0)
				ft_bresenham_line(vars, i * 30 + y, j * 30 + x, \
				(i + 1) * 30 + y, j * 30 + x, 0xFF0000);
			if (j + 1 < mat->cols && mat->matrix[i][j + 1] > 0)
				ft_bresenham_line(vars, i * 30 + y, j * 30 + x, \
				i * 30 + y, (j + 1) * 30 + x, 0xFF0000);
			if (i + 1 < mat->rows && mat->matrix[i + 1][j] == 0)
				ft_bresenham_line(vars, i * 30 + y, j * 30 + x, \
				(i + 1) * 30 + y, j * 30 + x, 0xFFFFFF);
			if (j + 1 < mat->cols && mat->matrix[i][j + 1] == 0)
				ft_bresenham_line(vars, i * 30 + y, j * 30 + x, \
				i * 30 + y, (j + 1) * 30 + x, 0xFFFFFF);
		}
	}
}
