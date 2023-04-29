/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 14:28:14 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 16:35:28 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*aloc_mem;

	aloc_mem = malloc(count * size);
	if (aloc_mem == NULL)
	{
		return (NULL);
	}
	ft_bzero(aloc_mem, (count * size));
	return (aloc_mem);
}

/*
function contiguously allocates enough space for count objects
The allocated memory is filled with bytes of value zero. bzero/ memset
var = malloc(sizeof(whatever) * amountofwhatever);
size_t Unlike standard longs unsigned longs won't store negative numbers, 
making their range from 0 to 4,294,967,295
int 2147483647 -2147483648
free in main
*/
