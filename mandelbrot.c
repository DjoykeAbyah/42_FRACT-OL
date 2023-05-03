/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:23:44 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/03 21:48:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	get_mandelbrot(double x, double y)
{
	double	x0;
	double	y0;
	double	xtemp;
	double	i;

	x0 = x;
	y0 = y;
	i = 0;
	while (((x * x) + (y * y)) <= 4 && i < MAX)
	{
		xtemp = (x * x) - (y * y) + x0; // wordt het groter of kleiner?
		y = 2 * (x * y) + y0;
		x = xtemp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_fractol *data)
{
	double		x;
	double		y;
	double		i;
	uint32_t	color;
	double		arr[2];

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		arr[0] = -2 + (x / WIDTH) * (2 - -2);
		while (y < HEIGHT)
		{
			arr[1] = 2 + (y / HEIGHT) * (-2 - 2);
			i = get_mandelbrot(arr[0], arr[1]);
			if (i == MAX)
				color = ft_pixel(0, 0, 0, 255);
			else
				color = ft_pixel(6 * i, 6 * i, 100 * i, 15 * i);
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
		y = 0;
	}
}

// void	init(t_fractol *data)
// {
// 	mandelbrot(data);
// }
