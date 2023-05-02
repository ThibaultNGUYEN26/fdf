/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:44:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 20:38:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*ft_allocate_character(t_matrix *mat, int fd, int size)
{
	char	*character;

	character = malloc(sizeof(int) * size * mat->rows);
	if (!character)
	{
		close(fd);
		return (NULL);
	}
	size = read(fd, character, (size * mat->rows) - 1);
	character[size] = '\0';
	return (character);
}

void	ft_matrix(t_matrix *mat, char *character, int rows, int cols)
{
	int		start;
	char	*number;
	int		j;

	start = mat->i;
	while (character[start] && character[start] != ' '
		&& character[start] != '\n')
		start++;
	number = malloc(sizeof(char *) * (start - mat->i));
	if (!number)
		return ;
	j = 0;
	while (character[mat->i] && character[mat->i] != ' '
		&& character[mat->i] != '\n')
		number[j++] = character[mat->i++];
	number[j] = '\0';
	mat->matrix[rows][cols] = ft_atoi(number);
	free(number);
}

int	ft_fill_matrix(char *file, t_matrix *mat)
{
	int		rows;
	int		cols;
	int		fd;
	int		size;
	char	*character;

	fd = ft_read_file(file);
	size = ft_strlen(get_next_line(fd));
	close(fd);
	fd = ft_read_file(file);
	character = ft_allocate_character(mat, fd, size);
	rows = 0;
	cols = 0;
	while (character[mat->i])
	{
		if (character[mat->i] != ' ')
		{
			ft_matrix(mat, character, rows, cols);
			cols++;
		}
		if (character[mat->i] == '\n')
		{
			rows++;
			cols = 0;
		}
		mat->i++;
	}
	return (free(character), fd);
}
