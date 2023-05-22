/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:16:58 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/22 17:05:24 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//julia math
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

//puts pixel on screen
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

// converts input to double, checks if double between fractal range
void	arg_julia(char **argv, t_fractol *data)
{
	data->j_x = ft_atod(argv[2]);
	data->j_y = ft_atod(argv[3]);
	if (data->j_x > 2 || data->j_x < -2)
		ft_exit("please input number between -2 and 2", 1);
	if (data->j_y > 2 || data->j_y < -2)
		ft_exit("please input number between -2 and 2", 1);
}
