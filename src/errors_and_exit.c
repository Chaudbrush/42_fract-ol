/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:11:36 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 11:17:08 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close_all(t_data *prog)
{
	mlx_destroy_image(prog->mlx, prog->img.img);
	mlx_destroy_window(prog->mlx, prog->win);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	exit (EXIT_SUCCESS);
}

int	ft_close_half(t_data *prog)
{
	mlx_destroy_window(prog->mlx, prog->win);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	exit (MLX_ERROR);
}

int	ft_close_mini(t_data *prog)
{
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	exit (MLX_ERROR);
}

int	ft_argc_error(char *str)
{
	if (str)
		ft_putstr(str);
	ft_putstr("Usage: ./fractol mandelbrot\n");
	ft_putstr("Usage: ./fractol julia <parameter> <parameter>\n");
	ft_putstr("Usage: ./fractol phoenix\n");
	exit (PARSE_ERROR);
}
