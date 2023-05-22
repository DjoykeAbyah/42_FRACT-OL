/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:17:58 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/22 20:02:10 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//checks if strings contain only digits
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

//checks for multiple -'s and +'s
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

// stringinput checken op digits
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
			ft_exit("input number 1", 1);
		if (sign > 1)
			ft_exit("input number 2", 1);
		if (argv[i] == '.' && !ft_isdigit(argv[i + 1]))
			ft_exit("input number 3", 1);
		if ((argv[i] == '-' || argv[i] == '+') && !ft_isdigit(argv[i + 1]))
			ft_exit("intput number 4", 1);
		if (!ft_sign_dot_num(argv))
			ft_exit("input number 5", 1);
		i++;
	}
}

//checks if argc is correct amount for mandelbrot, julia
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
