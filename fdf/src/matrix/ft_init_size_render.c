/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_size_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:03:58 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 18:03:07 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_init_size_render(t_matrix *mat)
{
	if (!mat)
		return ;
	mat->coords.case_size = 1;
	mat->coords.xo = 0;
	mat->coords.yo = 0;
	mat->size.north = INT_MAX;
	mat->size.south = INT_MIN;
	mat->size.east = INT_MIN;
	mat->size.west = INT_MAX;
	mat->size.dist_ver = 0;
	mat->size.dist_hor = 0;
	mat->c.height = 0.01;
	mat->c.angle1 = 45;
	mat->c.angle2 = 45;
	mat->c.rot_angle1 = 0;
	mat->c.rot_angle2 = 0;
	mat->mouse_prev_x = CENTER_X;
	mat->mouse_prev_y = CENTER_Y;
	mat->mouse_pressed = 0;
	mat->ortho = 0;
	mat->color_switch = 0;
}
