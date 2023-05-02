/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:43:24 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 19:53:27 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdarg.h>

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;35m"
# define BLUE "\033[1;36m"
# define WHITE "\033[1;37m"
# define EOC "\033[0;0m"

# define WIDTH 1080
# define HEIGHT 720

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

typedef struct s_matrix
{
	int	rows;
	int	cols;
	int	**matrix;
	int	i;
}	t_matrix;

int			**ft_allocate_matrix(int rows, int cols);
void		ft_count_lines(char *file, int *rows, int *cols);
int			ft_fill_matrix(char *file, t_matrix *mat);
void		ft_free_matrix(t_matrix matrix);
void		ft_print_matrix(t_matrix *matrix);
t_matrix	*ft_init_matrix(char *file);
int			ft_read_file(char *file);

char		*get_next_line(const int fd);

int			ft_atoi(char *str);
char		*ft_strchr(char *s, int c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		*ft_substr(char *s, int start, int len);

int			ft_close_window(void *param);
int			ft_key_hook(int key, void *param);
void		ft_display_matrix(t_matrix *mat, t_vars vars);

int			ft_printf(const char *s, ...);
int			ft_intlen(long n, char *base);

#endif
