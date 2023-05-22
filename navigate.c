/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   navigate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/20 18:50:12 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/22 19:57:43 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//event triggered function
void	ft_move(void *param)
{
	t_fractol	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_travel(data);
	ft_iter(data);
	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		ft_mouse_pos(data);
		choose(data);
	}
}

//increasing or decreasing iterations
void	ft_iter(t_fractol *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	{
		data->max += 10;
		choose(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		data->max -= 10;
		choose(data);
	}
}

//allows traveling in window
void	ft_travel(t_fractol *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		data->y[0] -= 0.1 / 2;
		data->y[1] -= 0.1 / 2;
		choose(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		data->y[0] += 0.1 / 2;
		data->y[1] += 0.1 / 2;
		choose(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->x[0] += 0.1 / 2;
		data->x[1] += 0.1 / 2;
		choose(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->x[0] -= 0.1 / 2;
		data->x[1] -= 0.1 / 2;
		choose(data);
	}
}

//zooming centre of current window
void	ft_zoom(double x, double y, void *param)
{
	t_fractol	*data;

	data = param;
	(void)x;
	if (y > 0)
	{
		data->x[0] = data->x[0] * 0.95;
		data->x[1] = data->x[1] * 0.95;
		data->y[0] = data->y[0] * 0.95;
		data->y[1] = data->y[1] * 0.95;
	}
	else if (y < 0)
	{
		data->x[0] = data->x[0] / 0.95;
		data->x[1] = data->x[1] / 0.95;
		data->y[0] = data->y[0] / 0.95;
		data->y[1] = data->y[1] / 0.95;
	}
	choose(data);
}

//pixels to coordinates
void	ft_mouse_pos(t_fractol *data)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	data->j_x = data->x[0] + ((double)x / WIDTH) * (data->x[1] - data->x[0]);
	data->j_y = data->y[1] + ((double)y / HEIGHT) * (data->y[0] - data->y[1]);
}
