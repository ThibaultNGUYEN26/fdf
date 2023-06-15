/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:35 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/23 20:34:01 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_not_in_str(char *s1, char *s2)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s2);
	while (s1[i])
	{
		if (ft_strcmp(ft_substr(s1, i, size), s2) == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
