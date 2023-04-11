/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:36:10 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/11 18:47:12 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	ft_count(const char *str, char c)
{
	int	i;
	int	test;
	int	counter;

	i = 0;
	test = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != c && test == 0)
		{
			test = 1;
			counter++;
		}
		else if (str[i] == c)
			test = 0;
		i++;
	}
	return (counter);
}

static char	*ft_allocate(const char *s, char c, int *i)
{
	int		j;
	char	*str;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	str = ft_substr(s, 0, j);
	*i += j - 1;
	return (str);
}

static void	ft_free(char **ret, int j)
{
	while (j >= 0)
		free(ret[j--]);
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			ret[j] = ft_allocate(&s[i], c, &i);
			if (ret[j++] == NULL)
				return (ft_free(ret, j - 1), NULL);
		}
	}
	ret[j] = NULL;
	return (ret);
}
