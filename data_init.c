/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:37:46 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/27 09:13:27 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_data(t_utils *utils, char **av)
{
	utils->offset_x = 0.0;
	utils->offset_y = 0.0;
	utils->zoom = 1.0;
	utils->color_flag = 0;
	utils->version = 0;
	utils->res[0] = 1;
	utils->res[1] = 2;
	utils->res[2] = 4;
	utils->res[3] = 8;
	utils->res[4] = 16;
	utils->res[5] = 32;
	utils->res[6] = 64;
	utils->res[7] = 128;
	utils->res[8] = 256;
	utils->res[9] = 512;
	utils->res[10] = 1024;
	utils->res_flag = 6;
	utils->max = utils->res[utils->res_flag];
	utils->mandelbrot[0] = 0;
	utils->mandelbrot[1] = 0;
	ft_init_julia(utils, av);
	ft_init_phoenix(utils);
}

void	ft_init_phoenix(t_utils *utils)
{
	utils->phoenix[0] = 0.5667;
	utils->phoenix[1] = 0;
	utils->phoenix[2] = 0.4;
	utils->phoenix[3] = 0.4;
	utils->phoenix[4] = 0.1;
	utils->phoenix[5] = -0.4;
	utils->phoenix[6] = 0.55;
	utils->phoenix[7] = 0.1;
	utils->phoenix[8] = 0;
	utils->phoenix[9] = 0.5;
	utils->phoenix[10] = 0.4;
	utils->phoenix[11] = 0;
	utils->phoenix[12] = 0.1;
	utils->phoenix[13] = 0.1;
	utils->phoenix[14] = -0.1;
	utils->phoenix[15] = 0.6;
	utils->phoenix[16] = -0.5;
	utils->phoenix[17] = -0.35;
	utils->phoenix[18] = 0.205;
	utils->phoenix[19] = -0.25;
	utils->phoenix[20] = 0.855;
	utils->phoenix[21] = 0.2955;
	utils->phoenix[22] = -0.53;
	utils->phoenix[23] = -0.35;
}

void	ft_init_julia(t_utils *utils, char **av)
{
	if (utils->check_julia == 1)
	{
		utils->julia[0] = atoi_double(av[2]);
		utils->julia[8] = atoi_double(av[3]);
	}
	else
	{
		utils->julia[0] = -0.80;
		utils->julia[8] = 0.156;
	}
	utils->julia[1] = 0.355;
	utils->julia[2] = 0.281215625;
	utils->julia[3] = 0.355534;
	utils->julia[4] = -1.188;
	utils->julia[5] = 0.29605;
	utils->julia[6] = -0.1;
	utils->julia[7] = -0.7475087485;
	utils->julia[9] = 0.355;
	utils->julia[10] = 0.0113825;
	utils->julia[11] = -0.337292;
	utils->julia[12] = 0.305;
	utils->julia[13] = 0.01885;
	utils->julia[14] = 0.651;
	utils->julia[15] = 0.0830715266;
}
