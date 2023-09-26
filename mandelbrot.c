/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:23:44 by dreijans      #+#    #+#                 */
/*   Updated: 2023/09/26 18:00:21 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @param x double containing x coordinate
 * @param y double containinf y coordinate
 * @param max integer holding limit of iterations
 * @brief code version of the mathematical formula to make a mandelbrot fractal
 * @return int i representing the amount of iterations this formula has done 
 * for the statement to be no longer true
*/
static double	get_mandelbrot(double x, double y, int max)
{
	double	x0;
	double	y0;
	double	xtemp;
	double	i;

	x0 = x;
	y0 = y;
	i = 0;
	while (((x * x) + (y * y)) <= 4 && i < max)
	{
		xtemp = (x * x) - (y * y) + x0;
		y = 2 * (x * y) + y0;
		x = xtemp;
		i++;
	}
	return (i);
}


/**
 * @param data struct containing data needed to make a fractal
 * @brief checks position of coordinates with the window size to put a pixel on that position.
 * using the mandelbrot formula to create an infinite amount of the image created while zooming.
 * while the iterations determine the color by multiplying them with with each iteration.
 * pos[X] = -2 + (x / WIDTH) * (2 - -2)
 * pos[Y] = 2 + (y / HEIGHT) * (-2 - 2)
*/
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
		pos[X] = data->x[0] + (x / WIDTH) * (data->x[1] - data->x[0]);
		while (y < HEIGHT)
		{
			pos[Y] = data->y[1] + (y / HEIGHT) * (data->y[0] - data->y[1]);
			i = get_mandelbrot(pos[X], pos[Y], data->max);
			if (i == data->max)
				color = ft_pixel(0, 0, 0, 255);
			else
				color = ft_pixel(20 * i, 6 * i, 100 * i, 15 * i);
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
		y = 0;
	}
}
