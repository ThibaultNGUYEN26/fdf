/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:35:19 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/11 19:32:11 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(void *mlx, void *win, int x, int y)
{
	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}

void	draw_map(char *file_path, t_vars *vars)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		i;
	char	**numbers;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Erreur : Impossible d'ouvrir le fichier.\n", 2);
		return ;
	}
	line = get_next_line(fd);
	y = 0;
	while (line != NULL)
	{
		i = 0;
		x = 0;
		numbers = ft_split(line, ' ');
		while (numbers[i])
		{
			if (ft_atoi(numbers[i]) == 0)
				mlx_pixel_put(vars->mlx, vars->win, x + 500, y + 200, 0xFFFFFF);
			if (ft_atoi(numbers[i]) == 10)
				mlx_pixel_put(vars->mlx, vars->win, x + 500, y + 200, 0xFF0000);
			i++;
			x += 50;
		}
		y += 50;
		ft_strdel(&line);
		ft_free_array((void **)numbers);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF Project");
		draw_map(argv[1], &vars);
		mlx_hook(vars.win, 17, 0, ft_close_window, vars.mlx);
		mlx_hook(vars.win, 2, 0, ft_key_hook, vars.mlx);
		mlx_loop(vars.mlx);
	}
	return (0);
}
