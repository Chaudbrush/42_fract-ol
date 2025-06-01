/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:48:42 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/31 19:07:34 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	argv_parse(t_data *prog, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		prog->utils.prog_name = "mandelbrot";
	else if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		prog->utils.prog_name = "julia";
		if (av[2] && av[3])
			julia_err(&prog->utils, av);
		else
			ft_argc_error("Missing input data for julia set\n");
	}
	else if (ft_strncmp(av[1], "phoenix", 8) == 0)
		prog->utils.prog_name = "phoenix";
	else
		ft_argc_error(NULL);
}

int	check_num(char *str)
{
	int	i;
	int	is_num;

	i = 0;
	is_num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			is_num++;
		i++;
	}
	return (is_num);
}

int	check_str(char *str)
{
	int	i;
	int	point_flag;
	int	other_flag;

	i = 0;
	point_flag = 0;
	other_flag = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			point_flag++;
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			other_flag++;
		i++;
	}
	if (point_flag > 1 || other_flag > 0)
		return (0);
	else
		return (1);
}

void	julia_err(t_utils *utils, char **av)
{
	double	x;
	double	y;

	x = atoi_double(av[2]);
	y = atoi_double(av[3]);
	if (!av[2][0] || !av[3][0])
		ft_argc_error("Empty string\n");
	if (check_num(av[2]) == 0 || check_num(av[3]) == 0)
		ft_argc_error("Invalid string, didn't have any number\n");
	if (!(check_str(av[2]) && check_str(av[3])))
		ft_argc_error("Invalid string, extra characters\n");
	else
	{
		if (x >= 2 || y >= 2 || x <= -2 || y <= -2)
			ft_putstr("Value won't produce an interesting set\n");
		ft_putstr("Loading input values!\n");
		utils->julia[0] = x;
		utils->julia[8] = y;
	}
}
