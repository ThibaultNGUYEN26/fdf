/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:30:21 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/15 19:22:01 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_count_lines(char *file, int *rows, int *cols)
{
	int		fd;
	char	caractere;
	int		read_nb;

	fd = ft_read_file(file);
	read_nb = 0;
	while (read(fd, &caractere, sizeof(char)) > 0)
	{
		if (caractere == '\n')
		{
			*rows += 1;
			read_nb = 2;
		}
		else if ((caractere == ' ' || caractere == '\t') && read_nb != 2)
			read_nb = 0;
		else if (!read_nb && read_nb != 2)
		{
			*cols += 1;
			read_nb = 1;
		}
	}
	close(fd);
}

static int	ft_buffer(char *file)
{
	int	fd;
	int	caractere;
	int	i;

	fd = ft_read_file(file);
	i = 0;
	while (read(fd, &caractere, sizeof(char)) > 0)
		i++;
	close(fd);
	return (i);
}

static void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	**ft_matrix(char *file)
{
	int		fd;
	char	*buffer;
	int		**matrix;
	int		rows;
	int		cols;
	int		bytes_read;
	int		i;

	rows = 0;
	cols = 0;
	ft_count_lines(file, &rows, &cols);
	matrix = ft_allocate_matrix(rows, cols);
	if (!matrix)
		return (NULL);
	fd = ft_read_file(file);
	buffer = malloc(sizeof(int) * ft_buffer(file));
	bytes_read = read(fd, buffer, sizeof(buffer));
	buffer[bytes_read] = '\0';
	rows = 0;
	cols = 0;
	if (bytes_read > 0)
	{
		i = -1;
		while (++i < bytes_read)
		{
			if (buffer[i] >= '0' && buffer[i] <= '9')
			{
				printf("i %d\n", i);
				matrix[rows][cols] = ft_atoi(&buffer[i]);
				printf("%c %d\n", buffer[9], matrix[rows][cols]);
				cols++;
			}
			else if (buffer[i] == ' ' || buffer[i] == '\n')
			{
				if (buffer[i] == '\n')
				{
					rows++;
					cols = 0;
				}
				i++;
			}
			else
				error_exit("Erreur : fichier texte invalide");
			if (buffer[i] == '\0')
				break ;
		}
	}
	if (close(fd) == -1)
		error_exit("Erreur lors de la fermeture du fichier");
	i = 0;
	int j = 0;
	rows = 11;
	cols = 19;
	printf("%d\n", matrix[0][3]);
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
	return (matrix);
}
