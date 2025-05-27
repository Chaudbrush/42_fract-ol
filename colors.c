/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:26:02 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/27 09:43:02 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	coloring(double i, t_utils utils)
{
	if (utils.color_flag % 4 < 2)
		return (bernstein_polynomials(i, utils));
	else
		return (cosine_coloring(i, utils));
}

int	bernstein_polynomials(double i, t_utils utils)
{
	int		color;
	double	t;

	t = interpolation(i, 0.01, 1, utils.max);
	if (utils.color_flag % 4 == 0)
	{
		color = (int)(9 * (1 - t) * t * t * t * 255) << 16;
		color |= (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8;
		color |= (int)(8.5 * (1 - t) * (0.75 - t) * (1 - t) * t * 200);
	}
	else
	{
		color = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255) << 16;
		color |= (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8;
		color |= (int)(8.5 * (1 - t) * t * t * t * 255);
	}
	return (color);
}

int	cosine_coloring(double i, t_utils utils)
{
	int		color;
	double	t;

	t = i / utils.max;
	i = i - log(t) / log(2);
	if (utils.color_flag % 4 == 2)
	{
		color = (int)(256 * (1 + cos(PI2 * log(i) / 13)) / 2) << 16;
		color |= (int)(175 * (1 + cos(PI2 * log(i) / 13)) / 2) << 8;
		color |= (int)(120 * (1 + cos(PI2 * log(i) / 13)) / 2);
	}
	else
	{
		color = (int)(100 * (1 + cos(PI2 * ((0.90 * t) + 0.65)))) << 16;
		color |= (int)(10 * (1 + cos(PI2 * ((0.4 * t) + 0.5)))) << 8;
		color |= (int)(70 * (1 - cos(PI2 * ((0.65 * t) + 0.5))));
	}
	return (color);
}
