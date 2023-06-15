/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_gestions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:09:10 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/15 19:06:41 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_zoom_in_gestion(t_matrix *mat)
{
	if (mat->rows < 20 || mat->cols < 20)
		mat->coords.case_size += 10;
	else if (mat->rows < 50 || mat->cols < 50)
		mat->coords.case_size += 8;
	else if (mat->rows < 100 || mat->cols < 100)
		mat->coords.case_size += 6;
	else if (mat->rows < 200 || mat->cols < 200)
		mat->coords.case_size += 4;
	else if (mat->rows < 400 || mat->cols < 400)
		mat->coords.case_size += 2;
	else if (mat->rows < 600 || mat->cols < 600)
		mat->coords.case_size++;
}

static void	ft_check_zoom_out(t_matrix *mat, int value)
{
	if (mat->coords.case_size - value >= 0)
		mat->coords.case_size -= value;
}

void	ft_zoom_out_gestion(t_matrix *mat)
{
	if (mat->coords.case_size > 0)
	{
		if (mat->rows < 20 || mat->cols < 20)
			ft_check_zoom_out(mat, 10);
		else if (mat->rows < 50 || mat->cols < 50)
			ft_check_zoom_out(mat, 8);
		else if (mat->rows < 100 || mat->cols < 100)
			ft_check_zoom_out(mat, 6);
		else if (mat->rows < 200 || mat->cols < 200)
			ft_check_zoom_out(mat, 4);
		else if (mat->rows < 400 || mat->cols < 400)
			ft_check_zoom_out(mat, 2);
		else if (mat->rows < 600 || mat->cols < 600)
			ft_check_zoom_out(mat, 1);
	}
}

int	mouse_press_hook(int key, int x, int y, void *param)
{
	t_matrix	*mat;

	(void)x;
	(void)y;
	mat = (t_matrix *)param;
	if (key == 1)
		mat->mouse_pressed = 1;
	return (0);
}

int	mouse_release_hook(int key, int x, int y, void *param)
{
	t_matrix	*mat;

	(void)x;
	(void)y;
	mat = (t_matrix *)param;
	if (key == 1)
		mat->mouse_pressed = 0;
	return (0);
}
