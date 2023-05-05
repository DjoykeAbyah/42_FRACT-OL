/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:57:11 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/05 22:22:08 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./Libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include <stdio.h>

typedef struct s_fractol
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	double				arrx[2];
	double				arry[2];
}							t_fractol;

# define WIDTH 1000
# define HEIGHT 1000
# define MAX 100
# define X 0
# define Y 1

int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void			ft_hook(void *param);
double			ft_atod(char *str);
void			mandelbrot(t_fractol *data);
void			ft_scroll(double x, double y, void *param);

#endif
