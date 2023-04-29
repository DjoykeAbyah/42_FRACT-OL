/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 12:43:37 by dreijans      #+#    #+#                 */
/*   Updated: 2023/03/28 15:08:31 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmuch(unsigned int a)
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

static char	*uitoa(unsigned int n)
{
	char	*str;
	int		index;

	index = howmuch(n);
	str = ft_calloc(index + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	index--;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[index] = (n % 10) + 48;
		n = n / 10;
		index--;
	}
	return (str);
}

int	print_unsigned(unsigned int n)
{
	int		count;
	char	*nbr;

	count = -1;
	nbr = uitoa(n);
	if (nbr != NULL)
	{
		count = write (1, nbr, ft_strlen(nbr));
		free (nbr);
	}
	return (count);
}
