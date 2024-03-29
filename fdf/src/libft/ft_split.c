/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:34:10 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/21 17:04:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	ft_allocate(char *s, char c, int *i)
{
	int		j;
	int		nb;
	char	*tmp;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	tmp = ft_substr(s, 0, j);
	nb = ft_atoi(tmp);
	*i += j - 1;
	return (free(tmp), nb);
}

int	ft_split(int *tab, char *s, char c)
{
	int		i;
	int		j;

	if (!s)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c)
			tab[j++] = ft_allocate(&s[i], c, &i);
	return (j);
}
