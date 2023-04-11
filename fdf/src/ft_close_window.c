/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:34:23 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/11 16:43:46 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	ft_key_hook(int key, void *param)
{
	if (key == 53)
		ft_close_window(param);
	return (0);
}
