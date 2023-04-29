/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:55:26 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/11 16:51:05 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		i = (int)len -1;
		while (i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{	
		i = 0;
		while (i < (int)len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/* 
copies:
len bytes from string src to string dst.  
The two strings may overlap; 
the copy is always done in a non-destructive manner.

returns:
the original value of dst.
i = len -1? changes int to index 
int 10 = i9 
met overlap wil je kopieren vanaf het einde ander etc
bij memcpy geeft overlap undefined behavior, memmove overwrtites
*/
