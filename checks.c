/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 18:53:37 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/22 17:14:56 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//checks if strings contain only digits
void	digit_check(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (argv[i])
	{
		while (ft_isdigit(argv[i][j]))
		{
			if (!ft_isdigit(argv[i][j]))
				ft_exit("please input correct numbers", 1);
			j++;
		}
		i++;
	}
}

//checks for multiple -'s and +'s
void	ft_minus_plus_check(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '-' && argv[i][j + 1] == '-')
			ft_exit("please input correct numbers", 1);
		if (argv[i][j] == '+' && argv[i][j + 1] == '+')
			ft_exit("please input correct numbers", 1);
		i++;
	}
}

// stringinput checken op digits
void	ft_string_check(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	digit_check(argv);
	ft_minus_plus_check(argv);
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if ((argv[i][j] == '-' || argv[i][j] == '+'))
					j++;
				if (argv[i][j] == '.' && !ft_isdigit(argv[i][j + 1]))
					ft_exit("please input correct numbers", 1);
				ft_exit("please input correct numbers", 1);
			}
			j++;
		}
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
		arg_julia(argv, data);
	if (argc == 4)
		ft_string_check(argv);
}
