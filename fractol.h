/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:57:11 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/20 19:25:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./LIBFT/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include <stdio.h>

// double				x[2];// begin eind van fractol
// double				y[2];// same
typedef struct s_fractol
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	double				x[2];
	double				y[2];
	int					max;
	int					fractol;
	double				j_x;
	double				j_y;
}							t_fractol;

# define WIDTH 1000
# define HEIGHT 1000
# define X 0
# define Y 1

int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void			ft_move(void *param);
double			ft_atod(const char *str);
void			mandelbrot(t_fractol *data);
void			julia(t_fractol *data);
void			ft_scroll(double x, double y, void *param);
void			init(t_fractol *fractol, char **argv);
void			choose(t_fractol *fractol);
void			ft_mouse_pos(t_fractol *data);
void			ft_travel(t_fractol *data);
void			ft_zoom(t_fractol *data);
void			check_input(int argc, char **argv, t_fractol *data);
void			arg_julia(char **argv, t_fractol *data);
void			ft_string_check(char **argv);
void			ft_minus_plus_check(char **argv);
void			ft_color(t_fractol *data);

#endif
