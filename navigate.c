/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   navigate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 18:09:05 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/05 22:36:45 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hook(void *param)
{
	t_fractol	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		data->arry[0] -= 0.1 / 5;
		data->arry[1] -= 0.1 / 5;
		mandelbrot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		data->arry[0] += 0.1 / 5;
		data->arry[1] += 0.1 / 5;
		mandelbrot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->arrx[0] += 0.1 / 5;
		data->arrx[1] += 0.1 / 5;
		mandelbrot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->arrx[0] -= 0.1 / 5;
		data->arrx[1] -= 0.1 / 5;
		mandelbrot(data);
	}
}

void	ft_scroll(double x, double y, void *param)
{
	t_fractol	*data;

	data = param;
	(void)x;
	if (y > 0)//bigger
	{
		data->arrx[0] = data->arrx[0] * 0.5;
		data->arrx[1] = data->arrx[1] * 0.5;
		data->arry[0] = data->arry[0] * 0.5;
		data->arry[1] = data->arry[1] * 0.5;
		puts("Up!");
	}
	else if (y < 0)//smaller
	{
		data->arrx[0] = data->arrx[0] / 0.5;
		data->arrx[1] = data->arrx[1] / 0.5;
		data->arry[0] = data->arry[0] / 0.5;
		data->arry[1] = data->arry[1] / 0.5;
		puts("Down!");
	}
	mandelbrot(data);
}
