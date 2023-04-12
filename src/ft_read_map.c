/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:30:21 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/12 20:42:15 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	**ft_allocate_matrix(int rows, int cols)
{
	int	**matrix;
	int	i;

	matrix = malloc(rows * sizeof(int **));
	i = -1;
	while (++i < rows)
		matrix[i] = malloc(cols * sizeof(int *));
	return (matrix);
}

static void	ft_count_lines(char *file, int *rows, int *cols)
{
	int	fd;
	int	caractere;
	int	read_nb;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur : impossible d'ouvrir le fichier");
		exit(EXIT_FAILURE);
	}
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

void	draw_map(char *file, t_vars *vars)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		i;
	char	**numbers;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Erreur : Impossible d'ouvrir le fichier.\n", 2);
		return ;
	}
	line = get_next_line(fd);
	y = 0;
	while (line != NULL)
	{
		i = -1;
		x = 0;
		numbers = ft_split(line, ' ');
		i = 0;
		while (numbers[i])
		{
			if (ft_atoi(numbers[i]) == 0)
				mlx_pixel_put(vars->mlx, vars->win, x + 500, y + 200, 0xFFFFFF);
			if (ft_atoi(numbers[i]) == 10)
				mlx_pixel_put(vars->mlx, vars->win, x + 500, y + 200, 0xFF0000);
			i++;
			x += 30;
		}
		y += 30;
		ft_strdel(&line);
		ft_free_array((void **)numbers);
		line = get_next_line(fd);
	}
	close(fd);
}

int	**ft_matrix(char *file)
{
	int		**matrix;
	int		rows;
	int		cols;
	char	*line;
	int		fd;
	int		i;
	int		start;
	int		end;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Erreur : Impossible d'ouvrir le fichier.\n", 2);
		return (NULL);
	}
	rows = 0;
	cols = 0;
	i = -1;
	ft_count_lines(file, &rows, &cols);
	matrix = ft_allocate_matrix(rows, cols);
	line = get_next_line(fd);
	rows = 0;
	cols = 0;
	while (line != NULL)
	{
		printf("III %d\n", i);
		while (line[++i])
		{
			if (line[i] == ' ')
				++i;
			else
			{
				printf("JE SUIS LA\n");
				start = i;
				end = start;
				while (line[end] != ' ')
					++end;
				printf("%d\n", cols);
				printf("ATOI %d\n", ft_atoi(ft_substr(line, start, end - start)));
				printf("JE MARCHE PAS\n");
				++cols;
				i = end + 1;
			}
		}
		// for (int k = 0; k < 19; k++)
		// 	printf("%d ", matrix[rows][k]);
		printf("\n");
		line = get_next_line(fd);
		rows++;
	}
	return (matrix);
}

void	ft_read_map(char *file)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	ft_count_lines(file, &rows, &cols);
	printf("Nombre de lignes : %d\n", rows);
	printf("Nombre de colonnes : %d\n", cols);
}
