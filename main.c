/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:42:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/03 21:41:04 by dreijans      ########   odam.nl         */
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
	printf("OK\n");
	fractol.image = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.image)
	{
		mlx_close_window(fractol.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	printf("OK\n");
	if (mlx_image_to_window(fractol.mlx, fractol.image, 0, 0) == -1)
	{
		mlx_close_window(fractol.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	printf("OK\n");
	mandelbrot(&fractol);
	printf("OK\n");
	// mlx_loop_hook(fractol.mlx, mandelbrot, &fractol);
	mlx_loop_hook(fractol.mlx, ft_hook, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
