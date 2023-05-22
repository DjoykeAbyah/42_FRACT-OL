/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:42:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/22 17:05:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 1)
		ft_exit("try ./fractol mandelbrot or ./fractol julia nbr nbr", 1);
	init(&fractol, argv);
	check_input(argc, argv, &fractol);
	fractol.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fractol.mlx)
		return (EXIT_FAILURE);
	fractol.image = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.image)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(fractol.mlx, fractol.image, 0, 0) == -1)
		return (EXIT_FAILURE);
	choose(&fractol);
	mlx_loop_hook(fractol.mlx, ft_move, &fractol);
	mlx_scroll_hook(fractol.mlx, ft_scroll, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
