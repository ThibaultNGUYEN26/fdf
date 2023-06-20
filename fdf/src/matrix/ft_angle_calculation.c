/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle_calculation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:52:16 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/19 18:59:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_angle_calculation(t_matrix *mat, int i, int j)
{
	mat->point[i][j].iso_x = (((j - i) * cos(mat->c.angle1 * M_PI / 180) * \
		cos(mat->c.rot_angle1 * M_PI / 180)) - (mat->point[i][j].z * \
		mat->c.height * sin(mat->c.rot_angle1 * M_PI / 180))) * \
		mat->coords.case_size / TEST + mat->coords.xo;
	mat->point[i][j].iso_y = (((-(mat->point[i][j].z * mat->c.height * \
		cos(mat->c.rot_angle2 * M_PI / 180)) + (j + i) * sin(mat->c.angle2 \
		* M_PI / 180)) * cos(mat->c.rot_angle2 * M_PI / 180)) + \
		(mat->point[i][j].z * mat->c.height * sin(mat->c.rot_angle2 * \
		M_PI / 180))) * mat->coords.case_size / TEST + mat->coords.yo;
}

void	ft_angle_adjust(t_matrix *mat, int i, int j)
{
	mat->point[i][j].iso_x = (((j - i) * cos(mat->c.angle1 * M_PI / 180) * \
	cos(mat->c.rot_angle1 * M_PI / 180)) - (mat->point[i][j].z * \
	mat->c.height * sin(mat->c.rot_angle1 * M_PI / 180))) * \
	mat->coords.case_size / TEST;
	mat->point[i][j].iso_y = (((-(mat->point[i][j].z * mat->c.height * \
	cos(mat->c.rot_angle2 * M_PI / 180)) + (j + i) * sin(mat->c.angle2 \
	* M_PI / 180)) * cos(mat->c.rot_angle2 * M_PI / 180)) - \
	(mat->point[i][j].z * mat->c.height * sin(mat->c.rot_angle2 * \
	M_PI / 180))) * mat->coords.case_size / TEST;
}
