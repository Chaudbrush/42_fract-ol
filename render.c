/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:50:06 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/30 08:43:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

double	interpolation(double num, double new_min, \
						double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min) \
			+ new_min);
}

int	render_fractal(t_img *img, t_utils *utils)
{
	int			color;
	double		grid;
	double		iterations;
	t_complex	screen;
	t_complex	c;

	grid = 2.0 * utils->zoom;
	screen.i = -1;
	while (++screen.i < HEIGHT)
	{
		screen.real = -1;
		while (++screen.real < WIDTH)
		{
			c.real = interpolation(screen.real, -grid, grid, WIDTH - 1) \
									+ utils->offset_x;
			c.i = interpolation(screen.i, grid, -grid, HEIGHT - 1) \
									+ utils->offset_y;
			iterations = check_name(c.real, c.i, utils);
			color = coloring(iterations, *utils);
			img_pixel_put(img, screen.real, screen.i, color);
		}
	}
	return (0);
}

int	ft_render(t_data *prog)
{
	if (prog->win == NULL)
		return (MLX_ERROR);
	render_fractal(&prog->img, &prog->utils);
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
	mlx_string_put(prog->mlx, prog->win, (WIDTH / 2) - 30, 20, \
					0xFFFFFF, prog->utils.prog_name);
	return (0);
}
