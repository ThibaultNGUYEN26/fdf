/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:16:25 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/30 22:47:04 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	**ft_allocate_matrix(int rows, int cols)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(rows * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (int *)malloc(cols * sizeof(int));
		if (!matrix[i])
		{
			while (i > 0)
				free(matrix[--i]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
