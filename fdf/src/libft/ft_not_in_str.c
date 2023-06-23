/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:35 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 18:15:13 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_not_in_str(char *s1, char *s2)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_strlen(s2);
	tmp = NULL;
	while (s1[i])
	{
		tmp = ft_substr(s1, i, size);
		if (ft_strcmp(tmp, s2) == 0)
			return (0);
		else
			i++;
		free(tmp);
	}
	return (1);
}
