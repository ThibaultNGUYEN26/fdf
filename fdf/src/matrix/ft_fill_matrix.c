/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:44:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/21 17:43:34 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_fill_with_colors(int fd, t_matrix *mat, char *line)
{
	int		i;
	int		j;
	char	**splitted_split;
	char	**splitted_file;

	i = -1;
	while (++i < mat->rows)
	{
		splitted_file = ft_split_char(line, ' ');
		j = -1;
		while (++j < mat->cols)
		{
			splitted_split = ft_split_char(splitted_file[j], ',');
			mat->matrix[i][j] = ft_atoi(splitted_split[0]);
			mat->point[i][j].color = ft_atoi_base(splitted_split[1] + 2, \
				"0123456789abcdef");
			ft_free(splitted_split, 1);
		}
		ft_free(splitted_file, mat->cols);
		line = get_next_line(fd);
	}
}

static void	ft_check_map(t_matrix *mat)
{
	ft_printf(RED "\n[ERROR]" WHITE \
		" : Map not properly formatted.\n" EOC);
	ft_free_matrix(mat);
	exit (1);
}

static void	ft_launch_check_map(t_matrix *mat, char *file, char *line, int fd)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	size = ft_split(mat->matrix[i], line, ' ');
	j = -1;
	while (++j < mat->cols)
		mat->point[0][j].color = 0xFFFFFF;
	while (++i < mat->rows)
	{
		line = get_next_line(fd);
		if (ft_split(mat->matrix[i], line, ' ') != size
			&& ft_not_in_str(file, "mars"))
			ft_check_map(mat);
		free(line);
		j = -1;
		while (++j < mat->cols)
			mat->point[i][j].color = 0xFFFFFF;
	}
}

void	ft_fill_matrix(char *file, t_matrix *mat)
{
	int		fd;
	char	*line;

	mat->point = ft_allocate_point(mat->rows, mat->cols);
	if (!mat->point)
		return ;
	fd = ft_read_file(file);
	line = get_next_line(fd);
	if (ft_not_in_str(line, ","))
		ft_launch_check_map(mat, file, line, fd);
	else
		ft_fill_with_colors(fd, mat, line);
	close(fd);
	free(line);
}
