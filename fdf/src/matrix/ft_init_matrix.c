/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:16 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/21 17:06:29 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_malloc_colors(t_matrix *mat, int i, int j)
{
	mat->color = malloc(sizeof(int *) * (mat->rows + 1));
	if (!mat->color)
		return ;
	i = -1;
	while (++i < mat->rows + 1)
	{
		mat->color[i] = malloc(sizeof(int) * (mat->cols + 1));
		if (!mat->color[i])
		{
			while (i > 0)
				free(mat->color[--i]);
			free(mat->color);
			return ;
		}
		j = -1;
		while (++j < mat->cols + 1)
			mat->color[i][j] = 1;
	}
}

t_matrix	*ft_init_matrix(char *file)
{
	t_matrix	*mat;
	int			i;
	int			j;

	mat = malloc(sizeof(t_matrix) * 1);
	if (!mat)
		return (NULL);
	ft_count_lines(file, &mat->rows, &mat->cols);
	mat->matrix = ft_allocate_matrix(mat->rows, mat->cols);
	i = 0;
	while (i < mat->rows)
	{
		j = 0;
		while (j < mat->cols)
		{
			mat->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	mat->i = 0;
	mat->map = file;
	ft_fill_matrix(file, mat);
	ft_malloc_colors(mat, i, j);
	return (mat);
}
