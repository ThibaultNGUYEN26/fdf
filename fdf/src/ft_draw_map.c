/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:17:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/15 18:51:43 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_print_matrix(char *file, int **matrix)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	i = 0;
	j = 0;
	rows = 0;
	cols = 0;
	ft_count_lines(file, &rows, &cols);
	printf("%d\n", matrix[10][18]);
	while (i < rows)
	{
		while (j < cols)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_map(char *file, int **matrix)
{
	ft_print_matrix(file, matrix);
}
