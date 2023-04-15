/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:43:24 by thibnguy          #+#    #+#             */
/*   Updated: 2023/04/15 18:24:07 by thibnguy         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

char	*get_next_line(const int fd);
int		ft_atoi(char const *str);
int		**ft_allocate_matrix(int rows, int cols);
int		ft_read_file(char *file);
void	ft_free_array(void **arr);
void	draw_map(char *file, int **matrix);
void	ft_count_lines(char *file, int *rows, int *cols);
int		**ft_matrix(char *file);
// void	ft_read_map(char *file);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_strdel(char **as);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_close_window(void *param);
int		ft_key_hook(int key, void *param);
int		ft_abs(int nb);

#endif
