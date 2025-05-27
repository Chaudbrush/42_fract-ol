/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:19:13 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/26 19:15:38 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_name(double c, double i, t_utils *utils)
{
	if (strcmp(utils->prog_name, "mandelbrot") == 0)
		return (mandelbrot(c, i, *utils));
	if (strcmp(utils->prog_name, "julia") == 0)
		return (julia(c, i, *utils));
	if (strcmp(utils->prog_name, "phoenix") == 0)
		return (phoenix(c, i, *utils));
	return (0);
}

int	mandelbrot(double x, double y, t_utils utils)
{
	int			iterations;
	double		tmp;
	t_complex	z;
	t_complex	z2;

	iterations = -1;
	z.real = utils.mandelbrot[0];
	z.i = utils.mandelbrot[1];
	z2.real = 0.0;
	z2.i = 0.0;
	while (++iterations < utils.max && z2.real + z2.i < 4.0)
	{
		tmp = z2.real - z2.i + x;
		z.i = (2 * z.real * z.i) + y;
		z.real = tmp;
		z2.real = z.real * z.real;
		z2.i = z.i * z.i;
	}
	return (iterations);
}

int	julia(double x, double y, t_utils utils)
{
	int			iterations;
	double		tmp;
	t_complex	z;
	t_complex	z2;

	iterations = -1;
	z.real = x;
	z.i = y;
	z2.real = z.real * z.real;
	z2.i = z.i * z.i;
	while (++iterations < utils.max && z2.real + z2.i < 4.0)
	{
		tmp = z2.real - z2.i + utils.julia[utils.version % 8];
		z.i = (2 * z.real * z.i) + utils.julia[(utils.version % 8) + 8];
		z.real = tmp;
		z2.real = z.real * z.real;
		z2.i = z.i * z.i;
	}
	return (iterations);
}

int	phoenix(double x, double y, t_utils utils)
{
	int			iterations;
	t_complex	tmp;
	t_complex	z;
	t_complex	old;

	iterations = -1;
	z.real = x;
	z.i = y;
	old.real = utils.phoenix[utils.version % 8];
	old.i = utils.phoenix[(utils.version % 8) + 8];
	while (++iterations < utils.max && z.real * z.real + z.i * z.i < 4.0)
	{
		tmp.real = z.real;
		tmp.i = z.i;
		z.real = z.real * z.real - z.i * z.i + \
					utils.phoenix[utils.version % 8] + \
					(utils.phoenix[(utils.version % 8) + 16] * old.real);
		z.i = (2 * tmp.real * tmp.i) + \
					utils.phoenix[(utils.version % 8) + 8] + \
					(utils.phoenix[(utils.version % 8) + 16] * old.i);
		old.real = tmp.real;
		old.i = tmp.i;
	}
	return (iterations);
}
