/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:51:34 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/31 16:58:59 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define MLX_ERROR 1
# define WIDTH 1000
# define HEIGHT 1000
# define PI2 6.28318530
# define PI 3.141592653

typedef struct s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct s_utils
{
	double			offset_x;
	double			offset_y;
	double			zoom;
	char			*prog_name;
	unsigned char	color_flag;
	unsigned char	version;
	unsigned char	check_julia;
	int				res[11];
	double			julia[16];
	double			phoenix[24];
	double			mandelbrot[2];
	int				max;
	int				res_flag;
}				t_utils;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_complex	complex;
	t_utils		utils;
}				t_data;

int		ft_mlx_init(t_data *prog);
void	handle_zoom_in(int x, int y, t_data *prog);
int		handle_keypress(int keypress, t_data *prog);
int		handle_mouse(int mouse, int x, int y, t_data *prog);

int		check_num(char *str);
int		check_str(char *str);
void	argv_parse(t_data *prog, char **av);
void	julia_err(t_utils *utils, char **av);

void	ft_init_data(t_utils *utils);
void	ft_init_julia(t_utils *utils);
void	ft_init_phoenix(t_utils *utils);

void	ft_putstr(char *str);
double	atoi_double(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_argc_error(char *str);
int		ft_close_all(t_data *prog);
int		ft_close_half(t_data *prog);
int		ft_close_mini(t_data *prog);

int		julia(double x, double y, t_utils utils);
int		phoenix(double x, double y, t_utils utils);
int		mandelbrot(double x, double y, t_utils utils);
int		check_name(double c, double i, t_utils *utils);

int		coloring(double i, t_utils utils);
int		cosine_coloring(double i, t_utils utils);
int		bernstein_polynomials(double i, t_utils utils);

int		ft_render(t_data *prog);
int		render_fractal(t_img *img, t_utils *utils);
void	img_pixel_put(t_img *img, int x, int y, int color);
double	interpolation(double num, double new_min, \
					double new_max, double old_max);

#endif
