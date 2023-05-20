/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 18:06:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/20 16:11:18 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *fractol, char **argv)
{
	fractol->y[0] = -2;
	fractol->y[1] = 2;
	fractol->x[0] = -2;
	fractol->x[1] = 2;
	fractol->max = 100;
	fractol->j_x = 0;
	fractol->j_y = 0.8;
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		fractol->fractol = 1;
	else if (!ft_strncmp(argv[1], "julia", 6))
		fractol->fractol = 2;
	else
	{
		ft_putendl_fd("please type mandelbrot and julia in lowercase", 1);
		exit(EXIT_FAILURE);
	}
}


void	choose(t_fractol *fractol)
{
	if (fractol->fractol == 1)
		mandelbrot(fractol);
	if (fractol->fractol == 2)
		julia(fractol);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	check_input(int argc, char **argv, t_fractol *data)
{
	(void)data;
	(void)argv;
	ft_string_check(argv);
	if (!(argc == 2 || argc == 4))
	{
		ft_putendl_fd("try ./fractol mandelbrot or ./fractol julia nbr nbr", 1);
		exit(EXIT_FAILURE);
	}
	else if (argc == 4)
		arg_julia(argv, data);
}
