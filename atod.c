/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atof.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 18:53:37 by dreijans      #+#    #+#                 */
/*   Updated: 2023/05/03 15:36:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_atof_first(char *str)
{
	long	i;
	double	number;

	i = 0;
	number = 0;
	if (!str)
		return (0);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		number = -number;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while ((str[i]) != '.')
	{
		if (ft_isdigit(str[i]))
			number = number + (str[i] - '0') * 10;
		i++;
	}
	return (number);
}

static double	ft_atof_second(char *str)
{
	long	i;
	double	number;
	long	len;

	i = 0;
	number = 0;
	len = ft_strlen(str);
	while (str[len] != '.')
	{
		if (str[len] == '.' && !ft_isdigit(str[len - 1]))
			return (0);
		if (ft_isdigit(str[len]))
			number = (number + (str[len] - '0')) / 10;
		len--;
	}
	return (number);
}

double	ft_atod(char *str)
{
	double	number;

	number = 0;
	if (ft_atof_first(str) != 0 && ft_atof_second(str) != 0)
		number = ft_atof_first(str) + ft_atof_second(str);
	return (number);
}

// int	main(void)
// {
// 	char	*str;
// 	float	number;

// 	str = "30.15";
// 	number = ft_atof(str);
// 	printf("%f\n", number);
// }