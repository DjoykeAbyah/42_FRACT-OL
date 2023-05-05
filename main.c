/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:42:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/05 22:13:28 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	fractol;

	fractol.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fractol.mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fractol.image = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.image)
	{
		mlx_close_window(fractol.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(fractol.mlx, fractol.image, 0, 0) == -1)
	{
		mlx_close_window(fractol.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fractol.arry[0] = -2;
	fractol.arry[1] = 2;
	fractol.arrx[0] = -2;
	fractol.arrx[1] = 2;
	mandelbrot(&fractol);
	mlx_loop_hook(fractol.mlx, ft_hook, &fractol);
	mlx_scroll_hook(fractol.mlx, (mlx_scrollfunc)ft_scroll, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
