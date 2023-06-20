/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:34:23 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 18:26:12 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_close_window(void *param)
{
	(void)param;
	ft_printf(GREEN "[INFO]" WHITE " MLX window closed.\n" EOC);
	exit(0);
	return (0);
}

int	ft_key_hook(int key, void *param)
{
	t_matrix	*mat;

	mat = (t_matrix *)param;
	if (key == ESC)
		ft_close_window(mat);
	else
		key_move_event(key, mat);
	return (0);
}
