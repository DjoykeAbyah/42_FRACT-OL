/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:17:58 by dreijans      #+#    #+#                 */
/*   Updated: 2023/09/26 17:52:28 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @param argv string representing a number
 * @brief checks the string for the ampount of '.''s
 * @return int representing amount of the char above found
*/
int	ft_is_dot(char *argv)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
			x++;
		i++;
	}
	return (x);
}

/**
 * @param argv string representing a number
 * @brief checks the string for the ampount of '-' and '+'
 * @return int representing amount of the char above found
*/
int	ft_sign(char *argv)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			x++;
		i++;
	}
	return (x);
}

/**
 * @param argv string representing a number
 * @brief checks the string if the content is a '.', '-', '+'
 * or char representation of a number.
 * @return 1 when the string contains only these character
 * 0 when the string contains other characters than the above mentioned
*/
int	ft_sign_dot_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
			i++;
		if (i == 0 && (argv[i] == '-' || argv[i] == '+'))
			i++;
		if (ft_isdigit(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * @param argv string to be checked for digits
 * @brief checks string for digits, gives custom error message
 * if the string does not represent a digit which can be converted
*/
void	ft_string_check(char *argv)
{
	int	i;
	int	dot;
	int	sign;

	i = 0;
	dot = ft_is_dot(argv);
	sign = ft_sign(argv);
	while (argv[i])
	{
		if (dot > 1)
			ft_exit("input number, error 1", 1);
		if (sign > 1)
			ft_exit("input number, error 2", 1);
		if (argv[i] == '.' && !ft_isdigit(argv[i + 1]))
			ft_exit("input number, error 3", 1);
		if ((argv[i] == '-' || argv[i] == '+') && !ft_isdigit(argv[i + 1]))
			ft_exit("intput number, error 4", 1);
		if (!ft_sign_dot_num(argv))
			ft_exit("input number, error 5", 1);
		i++;
	}
}

/**
 * @param argc int representing argument count
 * @param argv 2D array containing arguments given in the terminal
 * @param data struct containing data needed for a fractal
 * @brief checks if the argument count is enough for a mandelbrot or
 * julia fractal. Gives custon error message when argc is wrong.
 * when argc is 2: function does nothing means there is mandelbrot
 * when argc is 4: enters string_check function and then arg_julia function
*/
void	check_input(int argc, char **argv, t_fractol *data)
{
	if (argc != 2 && argc != 4)
		ft_exit("try ./fractol mandelbrot or ./fractol julia nbr nbr", 1);
	if (argc != 2 && data->fractol == 1)
		ft_exit("please try ./fractol mandelbrot", 1);
	if (argc != 4 && data->fractol == 2)
		ft_exit("please try ./fractol julia nbr nbr", 1);
	if (argc == 4)
	{
		ft_string_check(argv[2]);
		ft_string_check(argv[3]);
	}
	if (argc == 4)
		arg_julia(argv, data);
}
