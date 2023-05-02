/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:34:23 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/26 17:13:47 by thibnguy         ###   ########.fr       */
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
	if (key == 53)
		ft_close_window(param);
	ft_printf(GREEN "[INFO]" WHITE " MLX window closed.\n" EOC);
	return (0);
}
