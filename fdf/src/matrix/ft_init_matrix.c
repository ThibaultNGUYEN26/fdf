/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:16 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 20:31:35 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/* void	ft_print_matrix(t_matrix *mat)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < mat->rows)
	{
		j = 0;
		while (j < mat->cols)
		{
			ft_printf(CYAN "%d " EOC, mat->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
} */
void	ft_print_matrix(t_matrix *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->rows)
	{
		j = 0;
		while (j < mat->cols)
		{
			ft_printf(CYAN "%d" EOC, mat->matrix[i][j]);
			if (mat->matrix[i][j] == 0 && mat->matrix[i][j + 1] == 10)
				ft_printf(" ");
			else if (mat->matrix[i][j] == 10 && mat->matrix[i][j + 1] == 10)
				ft_printf(" ");
			else
				ft_printf("  ");
			j++;
		}
		i++;
		ft_printf("\n");
	}
	ft_printf("\n");
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
	close(ft_fill_matrix(file, mat));
	// ft_print_matrix(mat);
	return (mat);
}
