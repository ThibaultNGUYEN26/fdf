/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:17:49 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 14:23:12 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;
		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
