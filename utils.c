/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 18:06:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/22 17:19:44 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//init variables to reuse
void	init(t_fractol *fractol, char **argv)
{
	fractol->y[0] = -2;
	fractol->y[1] = 2;
	fractol->x[0] = -2;
	fractol->x[1] = 2;
	fractol->max = 100;
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		fractol->fractol = 1;
	else if (!ft_strncmp(argv[1], "julia", 6))
		fractol->fractol = 2;
	else
		ft_exit("try ./fractol mandelbrot or ./fractol julia nbr nbr", 1);
}

//chooses between starting mandelbrot or julia
void	choose(t_fractol *fractol)
{
	if (fractol->fractol == 1)
		mandelbrot(fractol);
	if (fractol->fractol == 2)
		julia(fractol);
}

//init the RGBA value in a 32 bit int
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

//nodig voor input parcing!
double	ft_atod(const char *str)
{
	double	decimal;
	double	number;
	int		sign;
	int		i;

	number = 0.0;
	decimal = 1.0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
		number = number * 10 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (ft_isdigit(str[i]))
		{
			number = number * 10 + (str[i++] - '0');
			decimal *= 10;
		}
	}
	return (sign * number / decimal);
}

//exit message and EXIT_FAILURE
void	ft_exit(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	exit(EXIT_FAILURE);
}
