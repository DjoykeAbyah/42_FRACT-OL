/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:33:51 by dreijans      #+#    #+#                 */
/*   Updated: 2023/03/28 15:08:22 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmuch(unsigned long int a)
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

static int	put_pointer(unsigned long int n)
{
	int	nbr;

	if ((n / 16) != 0)
		put_pointer(n / 16);
	if ((n % 16) < 10)
	{
		nbr = print_char((n % 16) + 48);
		if (nbr == -1)
			return (-1);
	}
	else
	{
		nbr = print_char((n % 16) + 87);
		if (nbr == -1)
			return (-1);
	}
	return (nbr);
}

int	print_ptr(unsigned long int n)
{
	int	count;
	int	nbr;
	int	tmp;

	tmp = print_str("0x");
	if (tmp == -1)
		return (-1);
	count = howmuch(n);
	nbr = put_pointer(n);
	if (nbr == -1)
		return (-1);
	return (count + tmp);
}
