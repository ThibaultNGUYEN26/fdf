/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:10:26 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 17:32:43 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_intlen(long n, char *base)
{
	int	len;
	int	result;

	len = 0;
	result = 0;
	while (base[len])
		len++;
	while (n)
	{
		n /= len;
		++result;
	}
	return (result);
}
