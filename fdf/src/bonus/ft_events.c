/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:05:55 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/19 20:19:35 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_test_ortho(t_matrix *mat)
{
	if (mat->ortho == 0)
		mat->ortho = 1;
	else
		mat->ortho = 0;
}

int	wheel_event(int key, int x, int y, void *param)
{
	t_matrix	*mat;

	(void)x;
	(void)y;
	mat = (t_matrix *)param;
	if (key == ZOOM_IN || key == ZOOM_OUT)
	{	
		if (key == ZOOM_IN)
			ft_zoom_in_gestion(mat);
		else if (key == ZOOM_OUT)
			ft_zoom_out_gestion(mat);
		ft_func_draw(mat);
		mlx_put_image_to_window(mat->data->mlx, mat->data->win, mat->data->img, \
			0, 0);
	}
	if (key == 1)
		mat->mouse_pressed = 1;
	return (0);
}

static void	ft_move(int key, t_matrix *mat)
{
	if (key == UP)
		mat->coords.yo -= 10;
	else if (key == DOWN)
		mat->coords.yo += 10;
	else if (key == LEFT)
		mat->coords.xo -= 10;
	else if (key == RIGHT)
		mat->coords.xo += 10;
}

int	key_move_event(int key, t_matrix *mat)
{
	mat->key = '0';
	ft_move(key, mat);
	if (key == W)
		mat->c.rot_angle2 += 3;
	else if (key == S)
		mat->c.rot_angle2 -= 3;
	else if (key == A)
		mat->c.rot_angle1 += 10;
	else if (key == D)
		mat->c.rot_angle1 -= 10;
	else if (key == PLUS)
		mat->c.height += 0.1;
	else if (key == MINUS)
		mat->c.height -= 0.1;
	else if (key == C)
		ft_switch_color(mat);
	else if (key == R)
		mat->color_switch = 0;
	else if (key == ENTER)
		ft_test_ortho(mat);
	ft_func_draw(mat);
	return (0);
}

int	mouse_movement_hook(int x, int y, void *param)
{
	t_matrix	*mat;
	int			mouse_dx;
	int			mouse_dy;

	mat = (t_matrix *)param;
	if (mat->mouse_pressed == 1)
	{
		mouse_dx = x - mat->size.mid_x;
		mouse_dy = y - mat->size.mid_y;
		mat->c.rot_angle1 += mouse_dx / 50;
		mat->c.rot_angle2 += mouse_dy / 50;
		mat->mouse_prev_x = x;
		mat->mouse_prev_y = y;
		ft_func_draw(mat);
		mlx_put_image_to_window(mat->data->mlx, mat->data->win, \
			mat->data->img, 0, 0);
	}
	return (0);
}
