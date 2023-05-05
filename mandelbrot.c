/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:23:44 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/05 21:59:25 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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
	double		pos[2];
	uint32_t	color;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		//pos[X] = -2 + (x / WIDTH) * (2 - -2);
		pos[X] = data->arrx[0] + (x / WIDTH) * (data->arrx[1] - data->arrx[0]);
		while (y < HEIGHT)
		{
			// pos[Y] = 2 + (y / HEIGHT) * (-2 - 2);
			pos[Y] = data->arry[1] + (y / HEIGHT) * (data->arry[0] - data->arry[1]);
			i = get_mandelbrot(pos[X], pos[Y]);
			if (i == MAX)
				color = ft_pixel(0, 0, 0, 255);
			else
				color = ft_pixel(20 * i, 6 * i, 100 * i, 15 * i);
				// color = ft_pixel(255, 0, 0, 255);
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
		y = 0;
	}
}
