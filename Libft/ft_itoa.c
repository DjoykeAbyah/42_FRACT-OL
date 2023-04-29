/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:43:26 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/14 14:29:05 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmuch(int a)
{
	int	i;

	i = 0;
	if (a <= 0)
		i = i + 1;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		index;
	long	num;

	num = n;
	index = howmuch(num);
	str = ft_calloc(index + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	index--;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num = num * -1;
		str[0] = '-';
	}
	while (num != 0)
	{
		str[index] = (num % 10) + 48;
		num = num / 10;
		index--;
	}
	return (str);
}

/*
Parameters n: 
the integer to convert.

Return value:
The string representing the integer.
NULL if the allocation fails.

External functs:
malloc

Description: 
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
minus before i???

<= 0 = i + 1 because you want space to print minus or a zero/
*/