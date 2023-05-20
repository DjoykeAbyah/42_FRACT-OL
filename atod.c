/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atod.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 18:53:37 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/20 19:24:56 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// stringinput checken op digits
//kan deze beter bij utils staan en static?
void	ft_string_check(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
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
				{
					ft_putendl_fd("please input correct numbers", 1);
					exit(EXIT_FAILURE);
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_minus_plus_check(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '-' && argv[i][j + 1] == '-')
		{
			ft_putendl_fd("please input correct number", 1);
			exit(EXIT_FAILURE);
		}
		if (argv[i][j] == '+' && argv[i][j + 1] == '+')
		{
			ft_putendl_fd("please input correct number", 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
