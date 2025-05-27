/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:44:17 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/27 10:46:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	prog;

	if (argc == 1)
		return (ft_argc_error(), 1);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		prog.utils.prog_name = "mandelbrot";
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		prog.utils.prog_name = "julia";
		if (argv[2] && argv[3])
			prog.utils.check_julia = 1;
		else
			prog.utils.check_julia = 0;
	}
	else if (ft_strncmp(argv[1], "phoenix", 7) == 0)
		prog.utils.prog_name = "phoenix";
	else
		return (ft_argc_error(), 1);
	ft_mlx_init(&prog, argv);
	mlx_loop_hook(prog.mlx, ft_render, &prog);
	mlx_key_hook(prog.win, handle_keypress, &prog);
	mlx_mouse_hook(prog.win, handle_mouse, &prog);
	mlx_hook(prog.win, 17, 0, ft_close_all, &prog);
	mlx_loop(prog.mlx);
}

int	ft_mlx_init(t_data *prog, char **av)
{
	prog->mlx = mlx_init();
	if (prog->mlx == NULL)
		return (MLX_ERROR);
	prog->win = mlx_new_window(prog->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (prog->win == NULL)
		return (free(prog->mlx), MLX_ERROR);
	prog->img.img = mlx_new_image(prog->mlx, WIDTH, HEIGHT);
	if (prog->img.img == NULL)
		return (ft_close_half(prog), MLX_ERROR);
	prog->img.addr = mlx_get_data_addr(prog->img.img, \
						&prog->img.bpp, &prog->img.line_len, &prog->img.endian);
	ft_init_data(&prog->utils, av);
	return (0);
}

int	handle_keypress(int keypress, t_data *prog)
{
	if (keypress == XK_Escape)
		ft_close_all(prog);
	if (keypress == XK_Up)
		prog->utils.offset_y += prog->utils.zoom / 4;
	if (keypress == XK_Down)
		prog->utils.offset_y -= prog->utils.zoom / 4;
	if (keypress == XK_Left)
		prog->utils.offset_x -= prog->utils.zoom / 4;
	if (keypress == XK_Right)
		prog->utils.offset_x += prog->utils.zoom / 4;
	if (keypress == XK_d)
		prog->utils.color_flag = (prog->utils.color_flag + 1);
	if (keypress == XK_a)
		prog->utils.color_flag = (prog->utils.color_flag - 1);
	if (keypress == XK_w)
		prog->utils.version = (prog->utils.version + 1);
	if (keypress == XK_s)
		prog->utils.version = (prog->utils.version - 1);
	if (keypress == XK_j)
		prog->utils.prog_name = "julia";
	if (keypress == XK_m)
		prog->utils.prog_name = "mandelbrot";
	if (keypress == XK_p)
		prog->utils.prog_name = "phoenix";
	return (0);
}

int	handle_mouse(int mouse, int x, int y, t_data *prog)
{
	(void)x;
	(void)y;
	if (mouse == Button4)
		prog->utils.zoom *= 0.9;
	if (mouse == Button5)
		prog->utils.zoom *= 1.1;
	if (mouse == Button3 && prog->utils.res_flag > 0)
	{
		prog->utils.res_flag -= 1;
		prog->utils.max = prog->utils.res[prog->utils.res_flag];
	}
	if (mouse == Button1 && prog->utils.res_flag < 10)
	{
		prog->utils.res_flag += 1;
		prog->utils.max = prog->utils.res[prog->utils.res_flag];
	}
	if (mouse == Button2)
		prog->utils.zoom = 1.0;
	return (0);
}
