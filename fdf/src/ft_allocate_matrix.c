/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:15:07 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/15 19:13:24 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**ft_allocate_matrix(int rows, int cols)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = (int **)malloc(cols * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		matrix[i] = (int *)malloc(rows * sizeof(int));
		if (!(matrix[i]))
		{
			j = -1;
			while (++j < i)
				free(matrix[j]);
			free(matrix);
			return (NULL);
		}
	}
	return (matrix);
}
