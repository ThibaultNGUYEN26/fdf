/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:57:06 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/20 16:05:34 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_count_lines(char *file, int *rows, int *cols)
{
	int		fd;
	char	character;
	int		read_nb;

	fd = ft_read_file(file);
	read_nb = 0;
	*rows = 0;
	*cols = 0;
	while (read(fd, &character, sizeof(char)) > 0)
	{
		if (character == '\n')
		{
			*rows += 1;
			read_nb = 2;
		}
		else if ((character == ' ' || character == '\t') && read_nb != 2)
			read_nb = 0;
		else if (!read_nb && read_nb != 2)
		{
			*cols += 1;
			read_nb = 1;
		}
	}	
	close(fd);
}
