/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:43:24 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/15 19:58:18 by thibnguy         ###   ########.fr       */
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
# include <limits.h>

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;35m"
# define BLUE "\033[1;36m"
# define WHITE "\033[1;37m"
# define EOC "\033[0;0m"

# define WIDTH 1080
# define HEIGHT 720
# define CENTER_X 540
# define CENTER_Y 360
# define TEST 7
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W 13
# define S 1
# define A 0
# define D 2
# define PLUS 24
# define MINUS 27

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_coords
{
	int	x0;
	int	y0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
	int	xo;
	int	yo;
	int	case_size;
}	t_coords;

typedef struct s_colors
{
	int	r_start;
	int	g_start;
	int	b_start;
	int	r_end;
	int	g_end;
	int	b_end;
	int	grad_red;
	int	grad_green;
	int	grad_blue;
}	t_colors;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_colors	col;
}	t_data;

typedef struct s_size
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	mid_hor;
	int	mid_ver;
	int	dist_ver;
	int	dist_hor;
	int	mid_x;
	int	mid_y;
}	t_size;

typedef struct s_point
{
	int	iso_x;
	int	iso_y;
	int	z;
	int	color;
}	t_point;

typedef struct s_const
{
	double	height;
	double	angle1;
	double	angle2;
	double	rot_angle1;
	double	rot_angle2;
}	t_const;

typedef struct s_matrix
{
	int			rows;
	int			cols;
	int			**matrix;
	int			i;
	int			color_start;
	int			color_end;
	char		*map;
	int			mouse_prev_x;
	int			mouse_prev_y;
	int			initial_x;
	int			initial_y;
	int			mouse_pressed;
	t_coords	coords;
	t_data		*data;
	t_size		size;
	t_point		**point;
	t_const		c;
}	t_matrix;

void		ft_zoom_in_gestion(t_matrix *mat);
void		ft_zoom_out_gestion(t_matrix *mat);
int			mouse_press_hook(int key, int x, int y, void *param);
int			mouse_release_hook(int key, int x, int y, void *param);
int			wheel_event(int key, int x, int y, void *param);
int			key_move_event(int key, t_matrix *mat);
// int			mouse_hook_event(int key, int x, int y, void *param);
int			mouse_movement_hook(int x, int y, void *param);

char		*get_next_line(const int fd);

int			ft_atoi_base(char *str, char *base);
int			ft_atoi(char *str);
int			ft_not_in_str(char *s1, char *s2);
void		ft_free(char **ret, int j);
char		**ft_split_char(char *s, char c);
int			ft_split(int *tab, char *s, char c);
char		*ft_strchr(char *s, int c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		*ft_substr(char *s, int start, int len);

int			**ft_allocate_matrix(int rows, int cols);
t_point		**ft_allocate_point(int rows, int cols);
void		ft_angle_calculation(t_matrix *mat, int i, int j);
void		ft_angle_adjust(t_matrix *mat, int i, int j);
void		ft_count_lines(char *file, int *rows, int *cols);
void		ft_fill_matrix(char *file, t_matrix *mat);
void		ft_free_matrix(t_matrix *mat);
t_matrix	*ft_init_matrix(char *file);
void		ft_init_size_render(t_matrix *mat);
int			ft_read_file(char *file);

void		ft_calculation_size(t_matrix *mat, int i, int j);
void		ft_find_max(int coords, int *max);
void		ft_find_min(int coords, int *min);
void		ft_adjust_size(t_matrix *mat);
void		ft_mlx_pixel_put(t_data *data, int *x_y, int color);
void		ft_bresenham(t_data *data, t_coords coords, int color_start, \
	int color_end);
void		ft_horizontal_calculation(t_matrix *mat, int i, int j);
void		ft_vertical_calculation(t_matrix *mat, int i, int j);
void		ft_check_horizontal(t_matrix *mat, int i, int j);
void		ft_check_vertical(t_matrix *mat, int i, int j);
int			ft_close_window(void *param);
int			ft_key_hook(int key, void *param);
void		ft_draw(t_matrix *mat);
void		ft_display_matrix(t_matrix *mat);
void		ft_init_data(t_matrix *mat);
void		ft_draw_background(t_matrix *mat);

int			ft_printf(const char *s, ...);
int			ft_intlen(long n, char *base);

#endif
