/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:16:58 by dreijans      #+#    #+#                 */
/*   Updated: 2023/09/26 18:21:04 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @param x double containing x coordinate
 * @param y double containinf y coordinate
 * @param max integer holding limit of iterations
 * @brief code version of the mathematical formula to make a julia fractal
 * @return int i representing the amount of iterations this formula has done 
 * for the statement to be no longer true
*/
static double	get_julia(double x, double y, t_fractol *data)
{
	double	xtemp;
	double	i;

	i = 0;
	while (((x * x) + (y * y)) <= 4 && i < data->max)
	{
		xtemp = (x * x) - (y * y) + data->j_x;
		y = 2 * (x * y) + data->j_y;
		x = xtemp;
		i++;
	}
	return (i);
}

/**
 * @param data struct containing data needed to make a fractal
 * @brief checks position of coordinates with the window size to put a pixel on that position.
 * using the julia formula to create an infinite amount of the image created while zooming.
 * while the iterations determine the color by multiplying them with with each iteration.
 * pos[X] = -2 + (x / WIDTH) * (2 - -2)
 * pos[Y] = 2 + (y / HEIGHT) * (-2 - 2)
*/
void	julia(t_fractol *data)
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
			i = get_julia(pos[X], pos[Y], data);
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

/**
 * @param argv 2D array containing command line arguments
 * @param data struct containing data needed to make a fractal
 * @brief adds arguments containing julia coodinates to the data struct
 * and checks if those arguments are within the boundaries of a fractal
 * if not it returns a custom error message and exits the program
*/
void	arg_julia(char **argv, t_fractol *data)
{
	data->j_x = ft_atod(argv[2]);
	data->j_y = ft_atod(argv[3]);
	if (data->j_x > 2 || data->j_x < -2)
		ft_exit("please input number between -2 and 2", 1);
	if (data->j_y > 2 || data->j_y < -2)
		ft_exit("please input number between -2 and 2", 1);
}
