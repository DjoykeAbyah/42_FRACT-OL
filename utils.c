/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 18:06:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/09/26 18:21:44 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @param fractol struct to be initialised
 * @param argv 2d char array containing command line arguments
 * @brief initialises struct with boundaries of a fractal
 * inspects arguments to identify the type of fractal and set
 * give int with value 1 or 2 to the fractol struct
 * gives a custom error message when the arguments are not correct
*/
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


/**
 * @param fractol fractol struct
 * @brief checks fractol int to determine which function
 * needs to be executed
*/
void	choose(t_fractol *fractol)
{
	if (fractol->fractol == 1)
		mandelbrot(fractol);
	if (fractol->fractol == 2)
		julia(fractol);
}


/**
 * @param r int representing red
 * @param g int representing green
 * @param b int representing blue
 * @param a int representing alpha (transparancy)
 * @brief takes four integer parameters: r, g, b, and a. 
 * And combines these four integer values using bitwise operators
 * to create a color.
 * @return 32-bit integer (of type int32_t) representing a pixel color.
*/
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * @param str constant char string
 * @brief takes the string and converts it to a double
 * @return double representation of the characters in the string
*/
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

/**
 * @param s char string
 * @param fd int representing file descriptor
 * @brief takes content of the string and displays it at corresponding
 * file descriptor as a message before exiting the program
*/
void	ft_exit(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	exit(EXIT_FAILURE);
}
