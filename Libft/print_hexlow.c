/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hexlow.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 18:54:57 by dreijans      #+#    #+#                 */
/*   Updated: 2023/03/28 15:07:37 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmuch(unsigned int a)
{
	int	i;

	i = 0;
	if (a == 0)
		i++;
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

static char	*uitoa(unsigned int n)
{
	char	*str;
	int		index;
	int		mod;

	index = howmuch(n);
	str = ft_calloc(index + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	index--;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		mod = n % 16;
		if (mod < 10)
			str[index] = mod + '0';
		else
			str[index] = (mod - 10) + 'a';
		n = n / 16;
		index--;
	}
	return (str);
}

int	print_hexlow(unsigned int n)
{
	int		count;
	char	*nbr;

	count = -1;
	nbr = uitoa(n);
	if (nbr)
	{
		count = write(1, nbr, ft_strlen(nbr));
		free (nbr);
	}
	return (count);
}

/*
why do i get LONG max/min errors when i put long in the function and now i don't?
hex wil niet negatief.
*/